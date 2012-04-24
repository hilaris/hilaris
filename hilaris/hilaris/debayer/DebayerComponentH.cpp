#include "DebayerComponentH.h"

EnOscPictureType DebayerComponentH::getType()
{
	return OSC_PICTURE_HUE;
}

long unsigned int DebayerComponentH::getSize()
{
	return sizeof(ComponentHImage);
}

ComponentHImage* DebayerComponentH::getObject(uint16 width, uint16 height)
{
	return new ComponentHImage(width / 2, height / 2);
}

bool DebayerComponentH::debayer(RawImage* raw, Image* image)
{
	return raw->debayerFast((ComponentHImage*)image);
}
