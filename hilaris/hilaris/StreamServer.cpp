#include "StreamServer.h"
#include <pthread.h>


bool StreamServer::start()
{
	pthread_create(&this->thread, NULL, sendData, (void*) "blabla");
	return true;
}

void* StreamServer::sendData(void* arg)
{
	while(1)
	{
		char* msg = (char*)arg;
		printf("message: %s\n", msg);
	}
	
	return arg;
}

bool StreamServer::stop()
{
	pthread_cancel(this->thread);
	return true;
}
