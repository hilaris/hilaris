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
	return new ComponentHImage(width, height);
}

bool DebayerComponentH::debayer(RawImage* raw, Image* image)
{
	ComponentHImage b = ComponentHImageFactory::getFastDebayered(raw);
	
	memcpy(image, &b, sizeof(b));
	
	return true;
}
