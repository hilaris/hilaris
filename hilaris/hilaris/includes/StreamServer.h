#ifndef _STREAM_SERVER_H_
#define _STREAM_SERVER_H_


#include "Hilaris.h"
#include <pthread.h>

class StreamServer {
	public:
		StreamServer(uint8 buffSize);
		bool start();
		static void *sendData(void* arg);
		bool stop();
		bool insertImage(Image img);
		Image getImage();
		
	private:
		pthread_t thread;
		pthread_mutex_t msg_lock;
		char* message;
		Image* images;
		int startBuff;
		int endBuff;
};

#endif 
