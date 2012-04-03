#include "StreamServer.h"

StreamServer::StreamServer(Camera* camera)
{
	this->clients.reserve(5); 
	this->camera = camera;
	this->startBuffer = 0;
	this->endBuffer = 0;
	this->connected = 0;
	
	//TODO image size from camera
	//this->buffer = (uint8*)malloc(OSC_CAM_MAX_IMAGE_WIDTH*OSC_CAM_MAX_IMAGE_HEIGHT);
	
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

	//TODO initialize image buffer


}

bool StreamServer::start()
{
	pthread_mutex_init(&this->bufferLock, NULL);
	if(pthread_create(&this->thread, NULL, sendData, (void*) this))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void* StreamServer::sendData(void* arg)
{	
	while(1)
	{
		StreamServer* s = (StreamServer*)arg;
		
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
		
		RawImage* img = s->camera->captureImage();
		
		//send data to all connected clients
		//TODO read image from buffer s->getImage();
		for(int i=0;i < s->connected;i++)
		{
			int len;
			char msg[] = "hallööö";
			
			if(s->writeable(s->clients.at(i)))
			{
				//send to client
				len = send(s->clients.at(i), img->getDataPtr(), img->getWidth() * img->getHeight(), 0);
				
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
		
		//printf("message: \n");
		usleep(1000);
	}
	
	return arg;
}

bool StreamServer::insertImage(RawImage img)
{
	pthread_mutex_lock(&this->bufferLock);
	sleep(1);
	//insert Image
	pthread_mutex_unlock(&this->bufferLock);  
	return false;
}

RawImage StreamServer::getImage()
{
	pthread_mutex_lock(&this->bufferLock);
	//sleep(1);
	//get Image from buffer
	RawImage i(*this->camera->captureImage());
	pthread_mutex_unlock(&this->bufferLock);  
	
	return i;
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
