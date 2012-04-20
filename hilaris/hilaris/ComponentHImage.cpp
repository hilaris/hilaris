#include "ComponentHImage.h"

ComponentHImage::ComponentHImage(uint16 width, uint16 height)
{
	this->width = width;
	this->height = height;
	
	this->setOscarContext();
}

EnOscPictureType ComponentHImage::getType()
{
	return OSC_PICTURE_HUE;
}

uint8* ComponentHImage::getDataPtr()
{
	return this->data;
}
