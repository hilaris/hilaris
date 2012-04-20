#include "DebayerComponentU.h"

EnOscPictureType DebayerComponentU::getType()
{
	return OSC_PICTURE_HUE;
}

long unsigned int DebayerComponentU::getSize()
{
	return sizeof(ComponentUImage);
}

ComponentUImage* DebayerComponentU::getObject(uint16 width, uint16 height)
{
	return new ComponentUImage(width, height);
}

bool DebayerComponentU::debayer(RawImage* raw, Image* image)
{
	ComponentUImage b = ComponentUImageFactory::getFastDebayered(raw);
	
	memcpy(image, &b, sizeof(b));
	
	return true;
}
