#include "DebayerComponentY.h"

EnOscPictureType DebayerComponentY::getType()
{
	return OSC_PICTURE_HUE;
}

long unsigned int DebayerComponentY::getSize()
{
	return sizeof(ComponentYImage);
}

ComponentYImage* DebayerComponentY::getObject(uint16 width, uint16 height)
{
	return new ComponentYImage(width, height);
}

bool DebayerComponentY::debayer(RawImage* raw, Image* image)
{
	ComponentYImage b = ComponentYImageFactory::getFastDebayered(raw);
	
	memcpy(image, &b, sizeof(b));
	
	return true;
}
