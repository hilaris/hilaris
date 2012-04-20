#include "YUV422Image.h"

YUV422Image::YUV422Image(uint16 width, uint16 height)
{
	this->width = width;
	this->height = height;
	
	this->setOscarContext();
}

EnOscPictureType YUV422Image::getType()
{
	return OSC_PICTURE_YUV_422;
}

uint8* YUV422Image::getDataPtr()
{
	return this->data;
}
