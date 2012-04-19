#include "ImageProducer.h"

void ImageProducer::run()
{
	while(!this->cancel)
	{
		Image* img = this->camera->captureImage();
		uint8* data = img->getDataPtr();
		
		this->buffer->insert(data);
		//printf("img count %d\n", ++count);
		usleep(1000);
	}
}
