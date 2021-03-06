#include "DebayerGreyscaleHalfsize.h"

EnOscPictureType DebayerGreyscaleHalfsize::getType()
{
	return OSC_PICTURE_GREYSCALE;
}

long unsigned int DebayerGreyscaleHalfsize::getSize()
{
	return sizeof(GreyscaleImage);
}

GreyscaleImage* DebayerGreyscaleHalfsize::getObject(uint16 width, uint16 height)
{
	return new GreyscaleImage(width/2, height/2);
}

bool DebayerGreyscaleHalfsize::debayer(RawImage* raw, Image* image)
{
	return raw->debayerHalfsize((GreyscaleImage*)image);
}
