#include "DebayerBGRBilinear.h"

EnOscPictureType DebayerBGRBilinear::getType()
{
	return OSC_PICTURE_BGR_24;
}

long unsigned int DebayerBGRBilinear::getSize()
{
	return sizeof(BGRImage);
}

BGRImage* DebayerBGRBilinear::getObject(uint16 width, uint16 height)
{
	return new BGRImage(width, height);
}

bool DebayerBGRBilinear::debayer(RawImage* raw, Image* image)
{
	/*
	BGRImage b = BGRImageFactory::getBilinearDebayered(raw);
	
	memcpy(image, &b, sizeof(b));
	*/
	
	enum EnBayerOrder order;
	OscCamGetBayerOrder(&order, 0, 0);
	
	uint8 pTemp[raw->getWidth() * 4];
	
	OscVisDebayerBilinearBGR(image->getDataPtr(), raw->getDataPtr(), raw->getWidth(), raw->getHeight(), pTemp, order);

	return true;
}
