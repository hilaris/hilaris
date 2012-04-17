#include "ImageProducer.h"

void ImageProducer::run()
{
	while(!this->cancel)
	{
		this->buffer->insert(this->camera->captureImage()->getDataPtr());
		usleep(1000);
	}
}
