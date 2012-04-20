#include "ComponentSImage.h"

ComponentSImage::ComponentSImage(uint16 width, uint16 height)
{
	this->width = width;
	this->height = height;
	
	this->setOscarContext();
}

EnOscPictureType ComponentSImage::getType()
{
	return OSC_PICTURE_HUE;
}

uint8* ComponentSImage::getDataPtr()
{
	return this->data;
}
