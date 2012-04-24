#ifndef _IMAGE_SENDER_NTHREAD_H
#define _IMAGE_SENDER_NTHREAD_H

#define MAX_CLIENTS 5
#define SOCK_ERROR -1

#include <vector>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>

#include "oscar.h"
#include "Camera.h"

class ImageSenderNoThread
{
	private:
		Camera* cam;
		int imgSize;
		
		bool cancel;
		
		std::vector<int> clients;
		int port;
		int connected;
		int srvSocket;
		struct  sockaddr_in addr;
		
		bool readable(int fd);
		bool writeable(int fd);
	public:
		ImageSenderNoThread(Camera* cam, int port, int imgSize);
		// from http://www.gotw.ca/publications/mill18.htm
		// Guideline #4: A base class destructor should be either public and virtual, or protected and nonvirtual.
		virtual ~ImageSenderNoThread();
		virtual void run();
};

#endif
