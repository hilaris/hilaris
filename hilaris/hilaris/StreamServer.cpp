#include "StreamServer.h"

StreamServer::StreamServer(Camera* camera, int port): camera(camera), port(port)
{
	this->imgSize = this->camera->getDebayeredImageSize();
	this->buffer = new ImageBuffer(this->imgSize, 6);
	this->imgProducer = new ImageProducer(this->camera, this->buffer);
	this->imgSender = new ImageSender(this->buffer, this->port, this->imgSize);
}

void StreamServer::start()
{
	this->imgProducer->start();
	this->imgSender->start();
	
	this->imgProducer->join();
	this->imgSender->join();
}

void StreamServer::stop()
{
	
}
