#include "StreamServer.h"

Thread* StreamServer::imgProducer;
Thread* StreamServer::imgSender;

StreamServer::StreamServer(Camera* camera, int port): camera(camera), port(port)
{
	signal(SIGINT, StreamServer::stop);
	
	//get size of the debayered image
	this->imgSize = this->camera->getDebayeredImageSize();
	
	//create a circular image buffer 
	this->buffer = new ImageBuffer(this->imgSize, 6);
	
	//create ImageProducer and ImageSender threads
	StreamServer::imgProducer = new ImageProducer(this->camera, this->buffer);
	StreamServer::imgSender = new ImageSender(this->buffer, this->port, this->imgSize);
}

void StreamServer::start()
{
	//start threads
	StreamServer::imgProducer->start();
	StreamServer::imgSender->start();
	
	//wait for threads to end
	StreamServer::imgProducer->join();
	StreamServer::imgSender->join();
}

void StreamServer::stop(int signum)
{
	pthread_cancel(StreamServer::imgProducer->thread);
	pthread_cancel(StreamServer::imgSender->thread);
}


