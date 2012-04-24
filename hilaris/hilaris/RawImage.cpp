#include "RawImage.h"

RawImage::RawImage(uint16 width, uint16 height)
{
	this->width = width;
	this->height = height;
}

uint8* RawImage::getDataPtr()
{
	return this->data;
}

EnOscPictureType RawImage::getType()
{
	// strunzwurscht
	return OSC_PICTURE_BGR_24;;
}

bool RawImage::debayerFast(BGRImage* image)
{
	return OscVisFastDebayerBGR(&this->getOscarContext(), &image->getOscarContext()) == SUCCESS;
}

bool RawImage::debayerFast(GreyscaleImage* image)
{
	printf("%d x %d\n",this->getOscarContext().width, this->getOscarContext().height);
	return OscVisFastDebayerGrey(&this->getOscarContext(), &image->getOscarContext()) == SUCCESS;
}


