#ifndef _STREAM_SERVER_NTHREAD_H_
#define _STREAM_SERVER_NTHREAD_H_

#define MAX_CLIENTS 5
#define SOCK_ERROR -1

#define REG_AEC_AGC_ENABLE 0xaf
#define CAM_REG_RESERVED_0x20 0x20
#define CAM_REG_CHIP_CONTROL 0x07

#include <signal.h>

#include "ImageSenderNoThread.h"
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
class StreamServerNoThread {
	public:
		/**
		 *  @brief Setting up this StreamServer by providing a Camera pointer
		 *         and a port which is optional.
		 */
		StreamServerNoThread(Camera* camera, int port=9003);
		
		/**
		 *  @brief Start streaming the debayered and processed Image.
		 *         This call will block until the threads are stopped
		 *         by the StreamServer::stop() method.
		 */
		void start();
		
		/**
		 *  @brief Static method to handle the SIGINT signal. Stops the producer 
		 *         and sender thread.
		 */
		static void stop(int signum);
		
	private:
		Camera* camera;
		
		int imgSize;
		int port;
};

#endif 
