#include "DebayerComponentS.h"

EnOscPictureType DebayerComponentS::getType()
{
	return OSC_PICTURE_HUE;
}

long unsigned int DebayerComponentS::getSize()
{
	return sizeof(ComponentSImage);
}

ComponentSImage* DebayerComponentS::getObject(uint16 width, uint16 height)
{
	return new ComponentSImage(width / 2, height / 2);
}

bool DebayerComponentS::debayer(RawImage* raw, Image* image)
{
	return raw->debayerFast((ComponentSImage*)image);
}
