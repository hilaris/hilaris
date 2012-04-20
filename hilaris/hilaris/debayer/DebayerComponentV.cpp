#include "DebayerComponentV.h"

EnOscPictureType DebayerComponentV::getType()
{
	return OSC_PICTURE_HUE;
}

long unsigned int DebayerComponentV::getSize()
{
	return sizeof(ComponentVImage);
}

ComponentVImage* DebayerComponentV::getObject(uint16 width, uint16 height)
{
	return new ComponentVImage(width, height);
}

bool DebayerComponentV::debayer(RawImage* raw, Image* image)
{
	ComponentVImage b = ComponentVImageFactory::getFastDebayered(raw);
	
	memcpy(image, &b, sizeof(b));
	
	return true;
}
