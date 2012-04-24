#include "ComponentYImage.h"

ComponentYImage::ComponentYImage(uint16 width, uint16 height)
{
	this->width = width;
	this->height = height;
	
	this->setOscarContext();
}

EnOscPictureType ComponentYImage::getType()
{
	return OSC_PICTURE_GREYSCALE;
}

uint8* ComponentYImage::getDataPtr()
{
	return this->data;
}
