#include "DebayerRaw.h"

EnOscPictureType DebayerRaw::getType()
{
	return OSC_PICTURE_GREYSCALE;
}

long unsigned int DebayerRaw::getSize()
{
	return sizeof(RawImage);
}

RawImage* DebayerRaw::getObject(uint16 width, uint16 height)
{
	return new RawImage(width, height);
}

bool DebayerRaw::debayer(RawImage* raw, Image* image)
{
	// darn fast
	return true;
}

