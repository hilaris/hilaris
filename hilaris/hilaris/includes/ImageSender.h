#ifndef _IMAGE_SENDER_H
#define _IMAGE_SENDER_H

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
#include "Thread.h"
#include "ImageBuffer.h"
#include "Debug.h"

class ImageSender : public Thread
{
	private:
		ImageBuffer* buffer;
		int imgSize;
		
		bool cancel;
		
		std::vector<int> clients;
		int port;
		int connected;
		int srvSocket;
		struct  sockaddr_in addr;
		
		bool readable(int fd);
		bool writeable(int fd);
	protected:
		virtual void run();
	public:
		ImageSender(ImageBuffer* buffer, int port, int imgSize);
};

#endif
