#include "StreamServer.h"

StreamServer::StreamServer(uint8 buffSize)
{}

bool StreamServer::start()
{
	pthread_mutex_init(&this->msg_lock, NULL);
	this->message = "blubb";
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
		s->getImage();
		printf("message: %s\n", s->message);
		usleep(100000);
	}
	
	return arg;
}

bool StreamServer::insertImage(Image img)
{
	pthread_mutex_lock(&this->msg_lock);
	sleep(1);
	//insert Image
	pthread_mutex_unlock(&this->msg_lock);  
	return false;
}

Image StreamServer::getImage()
{
	pthread_mutex_lock(&this->msg_lock);
	sleep(1);
	//get Image from buffer
	pthread_mutex_unlock(&this->msg_lock);  
	Image i(752, 480, OSC_PICTURE_BGR_24);
	return i;
}



bool StreamServer::stop()
{
	pthread_cancel(this->thread);
	pthread_join(this->thread, NULL);
	pthread_mutex_destroy(&this->msg_lock);
	return true;
}
