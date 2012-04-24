#include "ImageSenderNoThread.h"

ImageSenderNoThread::ImageSenderNoThread(Camera* cam, int port, int imgSize):cam(cam), imgSize(imgSize), cancel(false), port(port)
{
	this->clients.reserve(MAX_CLIENTS);
	this->connected = 0;
	
	//initialize socket
	int err;
	int i;

	this->srvSocket=socket(PF_INET, SOCK_STREAM, 0);
	if (this->srvSocket==SOCK_ERROR) 
	{
		perror("Could not start IP server\n");
	}

	i=1;
	setsockopt(this->srvSocket, SOL_SOCKET, SO_REUSEADDR, &i, sizeof(int));
	
	i=this->imgSize;
	setsockopt(this->srvSocket, SOL_SOCKET, SO_SNDBUF, &i, sizeof(int));
	
	bzero(&this->addr, sizeof(this->addr));
	addr.sin_port = htons(this->port);
	addr.sin_family = AF_INET;

	err = bind(this->srvSocket, (struct sockaddr*)&this->addr, sizeof(this->addr));
	if (this->srvSocket==SOCK_ERROR)
	{
		perror("Could bind socket\n");
	}

	err = listen(this->srvSocket, MAX_CLIENTS);
}

void ImageSenderNoThread::run()
{
	while(1)
	{
		usleep(1000);
		
		//accept pending client connections
		if(this->readable(this->srvSocket) && this->clients.size() <= MAX_CLIENTS)
		{
			this->clients.insert(this->clients.begin() + this->connected, accept(this->srvSocket, NULL, 0));
			if(this->clients.at(this->connected)==SOCK_ERROR)
			{
				OscLog(ERROR, "Could not accept client connection\n");
				this->clients.erase(this->clients.begin() + this->connected);
			}
			else
			{
				this->connected++;
			}
		}
		
		//if no image can be read skip sending image
		if((this->connected <= 0))
		{
			continue;
		}
		
		uint8* img = this->cam->captureImage()->getDataPtr();
		
		//send data to all connected clients
		for(int i=0;i < this->connected;i++)
		{
			int len;
			
			if(this->writeable(this->clients.at(i)))
			{
				len = send(this->clients.at(i), img, this->imgSize, 0);
			}
			
			if(this->readable(this->clients.at(i)))
			{
				int err;
				char dummy[100];
				
				err=read(this->clients.at(i), &dummy, sizeof(dummy)-1);
				if (err==0)
				{
					this->clients.erase(this->clients.begin() + i);
					this->connected--;
				}
			}			
		}
	}
}


bool ImageSenderNoThread::readable(int fd)
{
	int retval;
	fd_set r;
	struct timeval timeout;

	bzero(&timeout, sizeof(timeout));
	FD_ZERO(&r); 

	FD_SET(fd, &r);
	retval = select(fd+1, &r, NULL, NULL, &timeout);

	if (retval == -1) Debug::log(Debug::ERROR, "Select Error\n");

	if ((retval>0) && FD_ISSET(fd, &r)) 
		return TRUE;

	return FALSE;
}

bool ImageSenderNoThread::writeable(int fd)
{ 	
	int retval;
	fd_set w;
	struct timeval timeout;

	bzero(&timeout, sizeof(timeout));
	FD_ZERO(&w); 

	FD_SET(fd, &w);
	retval = select(fd+1, NULL, &w, NULL, &timeout);

	if (retval == -1) Debug::log(Debug::ERROR, "Select Error\n");

	if ((retval>0) && FD_ISSET(fd, &w)) 
		return TRUE;

	return FALSE;
}
