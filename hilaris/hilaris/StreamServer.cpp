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
	
	printf("joingin threads\n");
	this->imgProducer->join();
	printf("producer stopped\n");
	this->imgSender->join();
	printf("sender stopped\n");
}

void StreamServer::stop()
{
	
}
