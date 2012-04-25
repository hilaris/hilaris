#ifndef _IMAGE_PRODUCER_H_
#define _IMAGE_PRODUCER_H_

#include <unistd.h>

#include "oscar.h"
#include "Thread.h"
#include "ImageBuffer.h"
#include "Camera.h"

/**
 *  @brief This Thread implementation fetches Image objects from Camera and stores it.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 */
class ImageProducer : public Thread
{
	public:
	
		/**
		 *  @brief Create an ImageProducer.
		 *
		 *  @param camera The Camera object to read from.
		 *  @param buffer The ImageBuffer to store the Image data in a RingBuffer.
		 */
		ImageProducer(Camera* camera, ImageBuffer* buffer): buffer(buffer), camera(camera), cancel(false){}
		
	protected:
	
		virtual void run();
		
	private:
	
		ImageBuffer* buffer;
		Camera* camera;
		
		int imgSize;
		uint8 imgWidth;
		uint8 imgHeight;
		
		bool cancel;
};

#endif
