#ifndef _STREAM_SERVER_H_
#define _STREAM_SERVER_H_

#define MAX_CLIENTS 5
#define SOCK_ERROR -1

#include <signal.h>

#include "Thread.h"
#include "ImageBuffer.h"
#include "ImageProducer.h"
#include "ImageSender.h"
#include "Camera.h"

/**
 *  @brief Streaming Server for streaming debayered Images over the network.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 */
class StreamServer {
	public:
		/**
		 *  @brief Setting up this StreamServer by providing a Camera pointer.
		 */
		StreamServer(Camera* camera, int port=9003);
		
		/**
		 *  @brief Start streaming the debayered Image.
		 *  @return Success status.
		 */
		void start();
		
		/**
		 *  @brief Stop the streaming.
		 *  @return Success status.
		 */
		static void stop(int signum);
		
	private:
		static Thread* imgProducer;
		static Thread* imgSender;
		
		ImageBuffer* buffer;
		Camera* camera;
		
		int imgSize;
		int port;
};

#endif 
