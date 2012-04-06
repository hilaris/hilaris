#include "DebayerGreyscaleVector.h"

EnOscPictureType DebayerGreyscaleVector::getType()
{
	return OSC_PICTURE_GREYSCALE;
}

long unsigned int DebayerGreyscaleVector::getSize()
{
	return sizeof(GreyscaleImage);
}

GreyscaleImage* DebayerGreyscaleVector::getObject(uint16 width, uint16 height)
{
	return new GreyscaleImage(width/2, height/2);
}

bool DebayerGreyscaleVector::debayer(RawImage* raw, Image* image)
{
	GreyscaleImage b = GreyscaleImageFactory::getVectorDebayered(raw);
	
	memcpy(image, &b, sizeof(b));
	
	return true;
}
