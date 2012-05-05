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
	//register used commands
	CommandCollection::registerCommand("shutter", new ShutterWidthCommand(this->camera));
	CommandCollection::registerCommand("perspective", new PerspectiveCommand(this->camera));
	

	//start thread
	StreamServer::imgSender->start();
	
	while(!StreamServer::cancel)
	{
		while(!this->commands.empty())
		{
			std::string c = this->commands.front();
			this->commands.pop();
			
			CommandCollection::execute(c);
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


