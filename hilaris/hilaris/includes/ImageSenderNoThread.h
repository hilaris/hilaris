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

/**
 *  @brief Sends Image objects over the network without using Threads.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 */
class ImageSenderNoThread
{
	public:
		
		/**
		 *  @brief Create an ImageSenderNoThread.
		 *
		 *  @param cam The Camera to read images.
		 *  @param port Which port should this ImageSender use. Standard is 9003.
		 *  @param imgSize The size of the Images which will be sent.
		 */
		ImageSenderNoThread(Camera* cam, int port, int imgSize);
		
		/**
		 *  @brief Run this Thread.
		 */
		virtual void run();
		
		// from http://www.gotw.ca/publications/mill18.htm
		// Guideline #4: A base class destructor should be either public and virtual, or protected and nonvirtual.
		virtual ~ImageSenderNoThread();
		
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
};

#endif
