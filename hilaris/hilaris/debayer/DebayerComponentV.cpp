#include "DebayerComponentV.h"

EnOscPictureType DebayerComponentV::getType()
{
	return OSC_PICTURE_CHROM_V;
}

long unsigned int DebayerComponentV::getSize()
{
	return sizeof(ComponentVImage);
}

ComponentVImage* DebayerComponentV::getObject(uint16 width, uint16 height)
{
	return new ComponentVImage(width / 2, height / 2);
}

bool DebayerComponentV::debayer(RawImage* raw, Image* image)
{
	return raw->debayerFast((ComponentVImage*)image);
}
