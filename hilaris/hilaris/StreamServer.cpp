#include "StreamServer.h"

Thread* StreamServer::imgSender;

volatile sig_atomic_t StreamServer::cancel = 0; 

StreamServer::StreamServer(Camera* camera, int port): camera(camera), port(port)
{
	signal(SIGINT, StreamServer::stop);
	
	//set some magic flags
	/*
    OscCamSetRegisterValue(REG_AEC_AGC_ENABLE, 0x3);
    OscCamSetRegisterValue(CAM_REG_CHIP_CONTROL, 0x388);
    OscCamSetRegisterValue(CAM_REG_RESERVED_0x20, 0x3d5);
    */
	
	//get size of the debayered image
	this->imgSize = this->camera->getDebayeredImageSize();
	
	//create a circular image buffer 
	this->buffer = new ImageBuffer(this->imgSize, 6);
	
	//create mageSender thread
	StreamServer::imgSender = new ImageSender(this->buffer, &this->commands, this->port, this->imgSize);
}

void StreamServer::start()
{
	//start thread
	StreamServer::imgSender->start();
	
	while(!StreamServer::cancel)
	{
		while(!this->commands.empty())
		{
			std::string c = this->commands.front();
			this->commands.pop();
			
			int pos;
			if((pos = c.find_first_of(":"))>0)
			{
				std::string command = c.substr(0, pos);
				std::string param = c.substr(pos+1, c.length()-pos);
				
				if(command=="shutter")
				{
					printf("shutterwidth: %d\n", atoi(param.c_str()));
					this->camera->setShutterWidth(atoi(param.c_str()));
				}
				else if(command=="perspective")
				{
					this->camera->setPerspective(Camera::HORIZONTAL_MIRROR);
				}
			}
			else
			{
				if(c=="exit")
				{
					StreamServer::stop(0);
				}
			}
		}
	
		Image* img = this->camera->captureImage();
		uint8* data = img->getDataPtr();
		
		this->buffer->insert(data);
		usleep(2000);
	}
	
	//wait for sender thread to end
	StreamServer::imgSender->join();
}

void StreamServer::stop(int signum)
{
	StreamServer::cancel = 1;
	pthread_cancel(StreamServer::imgSender->thread);
}


