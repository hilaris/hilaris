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
	
	i=this->camera->getWidth()*this->camera->getHeight() * (OSC_PICTURE_TYPE_COLOR_DEPTH(this->camera->getDebayer()->getType())/8);
	setsockopt(this->srvSocket, SOL_SOCKET, SO_SNDBUF, &i, sizeof(int));
	
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
	#ifdef OSC_HOST
	printf("start lock %d\n", this->bufferLock.__data.__lock);
	#else
	printf("start lock %Ld\n", this->bufferLock.__m_lock.__status);
	#endif
	
	if((err=pthread_create(&this->thread, NULL, sendData, (void*) this))==0)
	{
		this->startBuffer = 0;
		if((err=pthread_create(&this->insert_thread, NULL, insertData, (void*) this))==0)
		{
			pthread_join(this->insert_thread, NULL);
			pthread_join(this->thread, NULL);
		}
		else
		{
			OscLog(DEBUG, "failed to start thread with error nr\n", err);
			return false;
		}
		
	}
	else
	{
		OscLog(DEBUG, "failed to start thread with error nr\n", err);
		return false;
	}
	return true;
}

void* StreamServer::insertData(void* arg)
{
	StreamServer* s = (StreamServer*)arg;
	#ifdef OSC_HOST
	printf("start insert lock %d\n", s->bufferLock.__data.__lock);
	#else
	printf("start insert lock %ld\n", s->bufferLock.__m_lock.__status);
	#endif

	while(1)
	{
		s->insertImage(s->camera->captureImage());
		OscLog(ALERT, "Picture taken and inserted in buffer\n");
		usleep(1000);
	}
}

void* StreamServer::sendData(void* arg)
{	

	OscLog(DEBUG, "sending thread started\n");
	StreamServer* s = (StreamServer*)arg;
	#ifdef OSC_HOST
	printf("start send lock %d\n", s->bufferLock.__data.__lock);
	#else
	printf("start send lock %ld\n", s->bufferLock.__m_lock.__status);
	#endif
		
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
		
		//send data to all connected clients
		for(int i=0;i < s->connected;i++)
		{
			int len;
			
			if(s->writeable(s->clients.at(i)))
			{
				int size = (OSC_PICTURE_TYPE_COLOR_DEPTH(s->camera->getDebayer()->getType())/8) * s->image->getWidth() * s->image->getHeight();
				len = send(s->clients.at(i), s->image->getDataPtr(), size, 0);
				OscLog(DEBUG, "sent %d bytes\n", len);
			}
			
			if(s->readable(s->clients.at(i)))
			{
				int err;
				char dummy[100];
				printf("readable disconnecting\n");
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
	printf("insert\n");
	#ifdef OSC_HOST
	printf("before insert lock %d\n", this->bufferLock.__data.__lock);
	#else
	printf("before insert lock %ld\n", this->bufferLock.__m_lock.__status);
	#endif
	pthread_mutex_lock(&this->bufferLock);
	OscLog(DEBUG, "insert image nr %d\n", this->countBuffer);
	
	int end = (this->startBuffer + this->countBuffer) % this->sizeBuffer;
    
    OscLog(DEBUG, "insert at buffer[%d] %p / start %d / count %d\n", end, this->imgBuffer[end], this->startBuffer, this->countBuffer);
	memcpy(this->imgBuffer[end], img, this->camera->getDebayer()->getSize());
	    
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
	printf("get\n");
	bool check = false;
	#ifdef OSC_HOST
	printf("before get lock %d\n", this->bufferLock.__data.__lock);
	#else
	printf("before get lock %ld\n", this->bufferLock.__m_lock.__status);
	#endif
	pthread_mutex_lock(&this->bufferLock);
	
	if((check = (!this->bufferIsEmpty())))
	{
		OscLog(ALERT, "getting image out of buffer at pos %d\n", this->startBuffer);
		
		OscLog(DEBUG, "get at %p size %ld into %p\n", this->imgBuffer[this->startBuffer], this->camera->getDebayer()->getSize(), this->image);
		memcpy(this->image, this->imgBuffer[this->startBuffer], this->camera->getDebayer()->getSize());
		
		this->startBuffer = (this->startBuffer + 1) % this->sizeBuffer;
		this->countBuffer--;
	}
	else
	{
		OscLog(DEBUG, "Buffer is still empty\n");
	}
			
	pthread_mutex_unlock(&this->bufferLock);  
	return check;	
}



bool StreamServer::stop()
{
	pthread_cancel(this->thread);
	pthread_join(this->thread, NULL);
	pthread_mutex_destroy(&this->bufferLock);

	for(int i = 0; i<this->sizeBuffer;i++)
	{
		delete this->imgBuffer[i];
	}
	
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
