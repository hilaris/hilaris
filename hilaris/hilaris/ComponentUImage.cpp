#include "ComponentUImage.h"

ComponentUImage::ComponentUImage(uint16 width, uint16 height)
{
	this->width = width;
	this->height = height;
	
	this->setOscarContext();
}

EnOscPictureType ComponentUImage::getType()
{
	return OSC_PICTURE_CHROM_U;
}

uint8* ComponentUImage::getDataPtr()
{
	return this->data;
}
