#include "DebayerComponentU.h"

EnOscPictureType DebayerComponentU::getType()
{
	return OSC_PICTURE_CHROM_U;
}

long unsigned int DebayerComponentU::getSize()
{
	return sizeof(ComponentUImage);
}

ComponentUImage* DebayerComponentU::getObject(uint16 width, uint16 height)
{
	return new ComponentUImage(width, height);
}

bool DebayerComponentU::debayer(RawImage* raw, Image* image)
{
	return raw->debayerFast((ComponentUImage*)image);
}
