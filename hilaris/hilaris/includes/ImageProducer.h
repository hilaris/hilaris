#ifndef _IMAGE_PRODUCER_H_
#define _IMAGE_PRODUCER_H_

#include <unistd.h>

#include "oscar.h"
#include "Thread.h"
#include "ImageBuffer.h"
#include "Camera.h"


class ImageProducer : public Thread
{
	private:
		ImageBuffer* buffer;
		Camera* camera;
		
		int imgSize;
		uint8 imgWidth;
		uint8 imgHeight;
		
		bool cancel;
	protected:
		virtual void run();
	public:
		ImageProducer(Camera* camera, ImageBuffer* buffer): buffer(buffer), camera(camera), cancel(false){}
};

#endif
