#include "StreamServer.h"

StreamServer::StreamServer(Camera* camera)
{
	this->clients.reserve(5); 
	this->camera = camera;
	
	this->startBuffer = 0;
	this->countBuffer = 0;
	this->sizeBuffer = 6;
	
	this->image = this->camera->getDebayer()->getObject(this->camera->getWidth(), this->camera->getHeight());
	
	for(int i = 0; i<this->sizeBuffer;i++)
	{
		this->imgBuffer[i] = this->camera->getDebayer()->getObject(this->camera->getWidth(), this->camera->getHeight());
		OscLog(DEBUG, "created image nr %d at %p\n", i, this->imgBuffer[i]);
	}
	
	this->connected = 0;
	
	//initialize socket
	int err;
	int i;

	this->srvSocket=socket(PF_INET, SOCK_STREAM, 0);
	if (this->srvSocket==SOCK_ERROR) 
		perror("Could not start IP server\n");

	i=1;
	setsockopt(this->srvSocket, SOL_SOCKET, SO_REUSEADDR, &i, sizeof(int));
	//i=1024*512;
	//setsockopt(this->srvSocket, SOL_SOCKET, SO_SNDBUF, &i, sizeof(int));
	bzero(&this->addr, sizeof(this->addr));
	addr.sin_port = htons(12345);
	addr.sin_family = AF_INET;

	err = bind(this->srvSocket, (struct sockaddr*)&this->addr, sizeof(this->addr));
	if (this->srvSocket==SOCK_ERROR) 
		perror("Could bind socket\n");

	err = listen(this->srvSocket, MAX_CLIENTS);


}

bool StreamServer::start()
{
	int err;
	pthread_mutex_init(&this->bufferLock, NULL);
	if((err=pthread_create(&this->thread, NULL, sendData, (void*) this))==0)
	{
		this->startBuffer = 0;
		OscLog(DEBUG, "starting to insert image sin buffer\n");
		while(1)
		{
			this->insertImage(this->camera->captureImage());
			OscLog(ALERT, "Inserted\n");
			usleep(1000);
		}
	}
	else
	{
		OscLog(DEBUG, "failed to start thread with error nr\n", err);
		return false;
	}
}

void* StreamServer::sendData(void* arg)
{	
	OscLog(DEBUG, "sending thread started\n");
	StreamServer* s = (StreamServer*)arg;
	while(1)
	{
		usleep(1000);
		
		//accept pending client connections
		if(s->readable(s->srvSocket))
		{
			printf("readable!!\n");
			s->clients.insert(s->clients.begin() + s->connected, accept(s->srvSocket, NULL, 0));
			if(s->clients.at(s->connected)==SOCK_ERROR)
			{
				OscLog(ERROR, "Could not accept client connection\n");
				s->clients.erase(s->clients.begin() + s->connected);
			}
			else
			{
				printf("connected client %d\n", s->connected);
				s->connected++;
			}
		}
		
		//if no image can be read skip sending image
		if((s->connected <= 0) || !s->getImage())
		{
			continue;
		}
		
		#if defined(OSC_HOST)
			s->image->save("stream.bmp");
		#endif
		
		#if defined(OSC_TARGET)
			s->image->save("/home/httpd/stream.bmp");
		#endif
		//send data to all connected clients
		for(int i=0;i < s->connected;i++)
		{
			int len;
			
			if(s->writeable(s->clients.at(i)))
			{
				len = send(s->clients.at(i), s->image->getDataPtr(), s->image->getWidth() * s->image->getHeight(), 0);
			}
			else
			{
				printf("disconnecting client %d\n", i);
				s->clients.erase(s->clients.begin() + i);
				s->connected--;
				continue;
			}
			
			if(s->readable(s->clients.at(i)))
			{
				int err;
				char dummy[100];

				err=read(s->clients.at(i), &dummy, sizeof(dummy)-1);
				if (err==0) {
					printf("disconnecting client %d\n", i);
					s->clients.erase(s->clients.begin() + i);
					s->connected--;
					printf("disconnected client %d\n", i);
				}
			}			
		}
	}
	
	return arg;
}

bool StreamServer::bufferIsFull()
{
	return this->countBuffer == this->sizeBuffer;
}

bool StreamServer::bufferIsEmpty()
{
	return this->countBuffer == 0;
}

bool StreamServer::insertImage(Image *img)
{
	pthread_mutex_lock(&this->bufferLock);
	OscLog(DEBUG, "insert image nr %d\n", this->countBuffer);
	
	int end = (this->startBuffer + this->countBuffer) % this->sizeBuffer;
    
    OscLog(DEBUG, "insert at buffer[%d] %p / start %d / count %d\n", end, this->imgBuffer[end], this->startBuffer, this->countBuffer);
	memcpy(this->imgBuffer[end], img, this->camera->getDebayer()->getSize());
	//*this->imgBuffer[end] = *img;
	    
    if (this->countBuffer == this->sizeBuffer)
    {
		this->startBuffer = (this->startBuffer + 1) % this->sizeBuffer; /* full, overwrite */
    }
    else
    {
    	this->countBuffer++;
    }
	
	pthread_mutex_unlock(&this->bufferLock);  
	OscLog(DEBUG, "After unlock\n");
	return true;
}

bool StreamServer::getImage()
{	
	if(!this->bufferIsEmpty())
	{
		pthread_mutex_lock(&this->bufferLock);
		OscLog(ALERT, "getting image out of buffer at pos %d\n", this->startBuffer);
		
		OscLog(DEBUG, "get at %p size %ld into %p\n", this->imgBuffer[this->startBuffer], this->camera->getDebayer()->getSize(), this->image);
		memcpy(this->image, this->imgBuffer[this->startBuffer], this->camera->getDebayer()->getSize());
		//*this->image = *this->imgBuffer[this->startBuffer];
		
		this->startBuffer = (this->startBuffer + 1) % this->sizeBuffer;
		this->countBuffer--;
		
		pthread_mutex_unlock(&this->bufferLock);  
	
		return true;
	}
	OscLog(DEBUG, "Buffer is still empty\n");	
	return false;	
}



bool StreamServer::stop()
{
	pthread_cancel(this->thread);
	pthread_join(this->thread, NULL);
	pthread_mutex_destroy(&this->bufferLock);
	return true;
}

bool StreamServer::readable(int fd)
{
	int retval;
	fd_set r;
	struct timeval timeout;

	bzero(&timeout, sizeof(timeout));
	FD_ZERO(&r); 

	FD_SET(fd, &r);
	retval = select(fd+1, &r, NULL, NULL, &timeout);

	if (retval == -1) 
		OscLog(ERROR, "Select Error\n");

	if ((retval>0) && FD_ISSET(fd, &r)) 
		return TRUE;

	return FALSE;
}

bool StreamServer::writeable(int fd)
{ 	
	int retval;
	fd_set w;
	struct timeval timeout;

	bzero(&timeout, sizeof(timeout));
	FD_ZERO(&w); 

	FD_SET(fd, &w);
	retval = select(fd+1, NULL, &w, NULL, &timeout);

	if (retval == -1) 
		OscLog(ERROR, "Select Error\n");

	if ((retval>0) && FD_ISSET(fd, &w)) 
		return TRUE;

	return FALSE;
}
