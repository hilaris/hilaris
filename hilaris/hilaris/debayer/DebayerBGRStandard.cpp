#include "DebayerBGRStandard.h"

EnOscPictureType DebayerBGRStandard::getType()
{
	return OSC_PICTURE_BGR_24;
}

long unsigned int DebayerBGRStandard::getSize()
{
	return sizeof(BGRImage);
}

BGRImage* DebayerBGRStandard::getObject(uint16 width, uint16 height)
{
	return new BGRImage(width, height);
}

bool DebayerBGRStandard::debayer(RawImage* raw, Image* image)
{
	BGRImage b = BGRImageFactory::getDebayered(raw);
	OscLog(DEBUG, "Before copy debayered\n");
	memcpy(image, &b, sizeof(b));
	OscLog(DEBUG, "After copy debayered\n");
	
	return true;
}
