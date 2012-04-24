#include "DebayerComponentY.h"

EnOscPictureType DebayerComponentY::getType()
{
	return OSC_PICTURE_GREYSCALE;
}

long unsigned int DebayerComponentY::getSize()
{
	return sizeof(ComponentYImage);
}

ComponentYImage* DebayerComponentY::getObject(uint16 width, uint16 height)
{
	return new ComponentYImage(width / 2, height / 2);
}

bool DebayerComponentY::debayer(RawImage* raw, Image* image)
{
	return raw->debayerFast((ComponentYImage*)image);
}
