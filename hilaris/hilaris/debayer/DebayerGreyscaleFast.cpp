#include "DebayerGreyscaleFast.h"

EnOscPictureType DebayerGreyscaleFast::getType()
{
	return OSC_PICTURE_GREYSCALE;
}

long unsigned int DebayerGreyscaleFast::getSize()
{
	return sizeof(GreyscaleImage);
}

GreyscaleImage* DebayerGreyscaleFast::getObject(uint16 width, uint16 height)
{
	return new GreyscaleImage(width/2, height/2);
}

bool DebayerGreyscaleFast::debayer(RawImage* raw, Image* image)
{
	return raw->debayerFast((GreyscaleImage*)image);
}
