#include "BGRImage.h"

BGRImage::BGRImage(uint16 width, uint16 height)
{
	this->width = width;
	this->height = height;
}

EnOscPictureType BGRImage::getType()
{
	return OSC_PICTURE_BGR_24;
}
