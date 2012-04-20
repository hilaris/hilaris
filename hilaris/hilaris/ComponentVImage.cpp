#include "ComponentVImage.h"

ComponentVImage::ComponentVImage(uint16 width, uint16 height)
{
	this->width = width;
	this->height = height;
	
	this->setOscarContext();
}

EnOscPictureType ComponentVImage::getType()
{
	return OSC_PICTURE_CHROM_V;
}

uint8* ComponentVImage::getDataPtr()
{
	return this->data;
}
