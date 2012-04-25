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

/**
 *  @brief This Thread implementation is able to send Image objects over the network.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since April 2012
 */
class ImageSender : public Thread
{
	public:
		
		/**
		 *  @brief Create an ImageSender.
		 *
		 *  @param buffer A pointer to an ImageBuffer.
		 *  @param port Which port should this ImageSender use. Standard is 9003.
		 *  @param imgSize The size of the Images which will be sent.
		 */
		ImageSender(ImageBuffer* buffer, int port, int imgSize);
		
	protected:
	
		virtual void run();
		
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
};

#endif
