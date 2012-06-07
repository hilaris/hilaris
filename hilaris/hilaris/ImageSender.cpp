#include "ImageSender.h"

ImageSender::ImageSender(ImageBuffer* buffer, std::queue<std::string>* commands, int port, int imgSize): buffer(buffer), commands(commands), imgSize(imgSize), cancel(false), port(port)
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
		perror("Could bind socket");
		printf("errornr: %d\n", err);
	}

	err = listen(this->srvSocket, MAX_CLIENTS);
}

void ImageSender::run()
{
	while(!this->cancel)
	{
		usleep(1000);
		
		//accept pending client connections
		if(this->readable(this->srvSocket))
		{
			this->clients.insert(this->clients.begin() + this->connected, accept(this->srvSocket, NULL, 0));
			if(this->clients.at(this->connected)==SOCK_ERROR)
			{
				Debug::log(Debug::ERROR, "Could not accept client connection\n");
				this->clients.erase(this->clients.begin() + this->connected);
			}
			else
			{
				this->connected++;
			}
		}
		
		//if no image can be read skip sending image
		if((this->connected <= 0) || this->buffer->isEmpty())
		{
			continue;
		}
		
		uint8* img = this->buffer->get();
		
		//send data to all connected clients
		for(int i=0;i < this->connected;i++)
		{
			if(this->writeable(this->clients.at(i)))
			{
				send(this->clients.at(i), img, this->imgSize, 0);
			}
			
			if(this->readable(this->clients.at(i)))
			{
				int err;
				char command[100];
				
				err=read(this->clients.at(i), &command, sizeof(command)-1);
				
				//zero indicated end of file
				if (err==0)
				{
					this->clients.erase(this->clients.begin() + i);
					this->connected--;
				}
				else if(err>0)
				{
					//terminate the command
					command[err] = '\0';
					//insert command into command queue
					this->commands->push(std::string(command));
				}
			}			
		}
	}
}


bool ImageSender::readable(int fd)
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

bool ImageSender::writeable(int fd)
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
