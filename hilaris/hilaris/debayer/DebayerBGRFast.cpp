#include "DebayerBGRFast.h"

EnOscPictureType DebayerBGRFast::getType()
{
	return OSC_PICTURE_BGR_24;
}

BGRImage* DebayerBGRFast::getObject(uint16 width, uint16 height)
{
	printf("getting object %d x %d\n", width, height);
	return new BGRImage(width/2, height/2);
}

bool DebayerBGRFast::debayer(RawImage* raw, Image* image)
{
	BGRImage b = BGRImageFactory::getFastDebayered(raw);
	
	memcpy(image, &b, sizeof(b));
	
	return true;
}

