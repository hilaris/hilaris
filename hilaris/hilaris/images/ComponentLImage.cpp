#include "ComponentLImage.h"

ComponentLImage::ComponentLImage(uint16 width, uint16 height)
{
	this->width = width;
	this->height = height;
	
	this->setOscarContext();
}

EnOscPictureType ComponentLImage::getType()
{
	return OSC_PICTURE_HUE;
}

uint8* ComponentLImage::getDataPtr()
{
	return this->data;
}
