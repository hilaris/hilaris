#include "StreamServer.h"
#include <pthread.h>


bool StreamServer::start()
{
	message = "blubb";
	pthread_create(&this->thread, NULL, sendData, (void*) this);
	return true;
}

void* StreamServer::sendData(void* arg)
{
	while(1)
	{
		StreamServer* s = (StreamServer*)arg;
		printf("message: %s\n", s->message);
	}
	
	return arg;
}

bool StreamServer::stop()
{
	pthread_cancel(this->thread);
	return true;
}
