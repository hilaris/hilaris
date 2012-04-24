#include "DebayerRGBStandard.h"

EnOscPictureType DebayerRGBStandard::getType()
{
	return OSC_PICTURE_RGB_24;
}

long unsigned int DebayerRGBStandard::getSize()
{
	return sizeof(RGBImage);
}

RGBImage* DebayerRGBStandard::getObject(uint16 width, uint16 height)
{
	return new RGBImage(width/2, height/2);
}

bool DebayerRGBStandard::debayer(RawImage* raw, Image* image)
{
	return raw->debayerFast((RGBImage*)image);
}
