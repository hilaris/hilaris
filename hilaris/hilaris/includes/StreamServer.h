#ifndef _STREAM_SERVER_H_
#define _STREAM_SERVER_H_


#include "Hilaris.h"
#include <pthread.h>

class StreamServer {
	public:
		bool start();
		static void *sendData(void* arg);
		bool stop();
	private:
		pthread_t thread;
		
};

#endif 
