#include "DebayerRGBStandard.h"

EnOscPictureType DebayerRGBStandard::getType()
{
	return OSC_PICTURE_RGB_24;
}

long unsigned int DebayerRGBStandard::getSize()
{
	return sizeof(RGBImage);
}

RGBImage* DebayerRGBStandard::getObject(uint16 width, uint16 height)
{
	return new RGBImage(width, height);
}

bool DebayerRGBStandard::debayer(RawImage* raw, Image* image)
{
	RGBImage b = RGBImageFactory::getFastDebayered(raw);
	
	memcpy(image, &b, sizeof(b));
	
	return true;
}
