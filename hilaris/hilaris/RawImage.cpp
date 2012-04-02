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
