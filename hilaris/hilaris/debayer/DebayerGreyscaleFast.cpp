#include "DebayerGreyscaleFast.h"

EnOscPictureType DebayerGreyscaleFast::getType()
{
	return OSC_PICTURE_GREYSCALE;
}

GreyscaleImage* DebayerGreyscaleFast::getObject(uint16 width, uint16 height)
{
	return new GreyscaleImage(width/2, height/2);
}

bool DebayerGreyscaleFast::debayer(RawImage* raw, Image* image)
{
	GreyscaleImage b = GreyscaleImageFactory::getFastDebayered(raw);
	
	memcpy(image, &b, sizeof(b));
	
	return true;
}