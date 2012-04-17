#include "DebayerGreyscaleFast.h"

EnOscPictureType DebayerGreyscaleFast::getType()
{
	return OSC_PICTURE_GREYSCALE;
}

long unsigned int DebayerGreyscaleFast::getSize()
{
	return sizeof(GreyscaleImage);
}

GreyscaleImage* DebayerGreyscaleFast::getObject(uint16 width, uint16 height)
{
	return new GreyscaleImage(width/2, height/2);
}

bool DebayerGreyscaleFast::debayer(RawImage* raw, Image* image)
{
	printf("befor factory\n");
	GreyscaleImage b = GreyscaleImageFactory::getFastDebayered(raw);
	printf("after factory\n");
	memcpy(image, &b, sizeof(b));
	printf("after memcpy\n");
	return true;
}
