#include "StreamServerNoThread.h"

StreamServerNoThread::StreamServerNoThread(Camera* camera, int port): camera(camera), port(port)
{
	//signal(SIGINT, StreamServer::stop);
	
	//set some magic flags
	/*
    OscCamSetRegisterValue(REG_AEC_AGC_ENABLE, 0x3);
    OscCamSetRegisterValue(CAM_REG_CHIP_CONTROL, 0x388);
    OscCamSetRegisterValue(CAM_REG_RESERVED_0x20, 0x3d5);
    */
	
	//get size of the debayered image
	this->imgSize = this->camera->getDebayeredImageSize();
}

void StreamServerNoThread::start()
{
	ImageSenderNoThread sender(this->camera, this->port, this->imgSize);
	sender.run();
}

void StreamServerNoThread::stop(int signum)
{

}


