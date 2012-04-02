#include "RawImage.h"

RawImage::RawImage(uint16 width, uint16 height)
{
	this->width = width;
	this->height = height;
}

EnOscPictureType RawImage::getType()
{
	// strunzwurscht
	return OSC_PICTURE_BGR_24;;
}
