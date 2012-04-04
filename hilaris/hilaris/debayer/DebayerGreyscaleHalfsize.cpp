#include "DebayerGreyscaleHalfsize.h"

EnOscPictureType DebayerGreyscaleHalfsize::getType()
{
	return OSC_PICTURE_GREYSCALE;
}

GreyscaleImage* DebayerGreyscaleHalfsize::getObject(uint16 width, uint16 height)
{
	return new GreyscaleImage(width/2, height/2);
}

bool DebayerGreyscaleHalfsize::debayer(RawImage* raw, Image* image)
{
	GreyscaleImage b = GreyscaleImageFactory::getHalfsizeDebayered(raw);
	
	memcpy(image, &b, sizeof(b));
	
	return true;
}
