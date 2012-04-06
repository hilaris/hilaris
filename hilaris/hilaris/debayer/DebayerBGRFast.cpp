#include "DebayerBGRFast.h"

EnOscPictureType DebayerBGRFast::getType()
{
	return OSC_PICTURE_BGR_24;
}

long unsigned int DebayerBGRFast::getSize()
{
	return sizeof(BGRImage);
}

BGRImage* DebayerBGRFast::getObject(uint16 width, uint16 height)
{
	OscLog(DEBUG, "getting object %d x %d\n", width, height);
	return new BGRImage(width/2, height/2);
}

bool DebayerBGRFast::debayer(RawImage* raw, Image* image)
{
	BGRImage b = BGRImageFactory::getFastDebayered(raw);
	
	memcpy(image, &b, sizeof(b));
	
	return true;
}

