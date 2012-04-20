#include "DebayerYUV422Fast.h"

EnOscPictureType DebayerYUV422Fast::getType()
{
	return OSC_PICTURE_YUV_422;
}

long unsigned int DebayerYUV422Fast::getSize()
{
	return sizeof(YUV422Image);
}

YUV422Image* DebayerYUV422Fast::getObject(uint16 width, uint16 height)
{
	return new YUV422Image(width/2, height/2);
}

bool DebayerYUV422Fast::debayer(RawImage* raw, Image* image)
{
	YUV422Image y = YUV422ImageFactory::getFastDebayered(raw);
	
	memcpy(image, &y, sizeof(y));
	
	return true;
}

