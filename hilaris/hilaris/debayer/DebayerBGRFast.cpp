#include "DebayerBGRFast.h"
#include <string.h>

EnOscPictureType DebayerBGRFast::getType()
{
	return OSC_PICTURE_BGR_24;
}

BGRImage* DebayerBGRFast::getObject(uint8 width, uint8 height)
{
	return new BGRImage(width/2, height/2);
}

bool DebayerBGRFast::debayer(RawImage* raw, Image* image)
{
	BGRImage b = BGRImageFactory::getFastDebayered(raw);
	
	memcpy(image, &b, sizeof(b));
	
	return true;
}

