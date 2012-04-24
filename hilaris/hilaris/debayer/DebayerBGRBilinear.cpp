#include "DebayerBGRBilinear.h"

EnOscPictureType DebayerBGRBilinear::getType()
{
	return OSC_PICTURE_BGR_24;
}

long unsigned int DebayerBGRBilinear::getSize()
{
	return sizeof(BGRImage);
}

BGRImage* DebayerBGRBilinear::getObject(uint16 width, uint16 height)
{
	return new BGRImage(width, height);
}

bool DebayerBGRBilinear::debayer(RawImage* raw, Image* image)
{
	return raw->debayerBilinear((BGRImage*)image);
}
