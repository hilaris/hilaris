#include "DebayerBGRHalfsize.h"

EnOscPictureType DebayerBGRHalfsize::getType()
{
	return OSC_PICTURE_BGR_24;
}

long unsigned int DebayerBGRHalfsize::getSize()
{
	return sizeof(BGRImage);
}

BGRImage* DebayerBGRHalfsize::getObject(uint16 width, uint16 height)
{
	return new BGRImage(width/2, height/2);
}

bool DebayerBGRHalfsize::debayer(RawImage* raw, Image* image)
{	
	return raw->debayerHalfsize((BGRImage*)image);
}
