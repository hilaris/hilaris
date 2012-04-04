#include "DebayerBGRBilinear.h"

EnOscPictureType DebayerBGRBilinear::getType()
{
	return OSC_PICTURE_BGR_24;
}

BGRImage* DebayerBGRBilinear::getObject(uint16 width, uint16 height)
{
	return new BGRImage(width, height);
}

bool DebayerBGRBilinear::debayer(RawImage* raw, Image* image)
{
	BGRImage b = BGRImageFactory::getBilinearDebayered(raw);
	
	memcpy(image, &b, sizeof(b));
	
	return true;
}
