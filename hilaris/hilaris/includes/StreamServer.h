#ifndef _STREAM_SERVER_H_
#define _STREAM_SERVER_H_

#define MAX_CLIENTS 5
#define SOCK_ERROR -1

#include "Hilaris.h"

#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <sys/select.h>

#include <vector>


class StreamServer {
	public:
		StreamServer(Camera* camera);
		bool start();
		bool stop();
		
	private:
		static void *sendData(void* arg);
		
		bool readable(int fd);
		bool writeable(int fd);
		
		bool bufferIsFull();
		bool bufferIsEmpty();
		bool insertImage(Image* img);
		bool getImage();
	
		pthread_t thread;
		pthread_mutex_t bufferLock;
		
		Image* image;
		Image* imgBuffer[6];
		int startBuffer;
		int countBuffer;
		int sizeBuffer;
				
		std::vector<int> clients;
		int connected;
		int srvSocket;
		struct  sockaddr_in addr;
		
		Camera* camera;
};

#endif 
