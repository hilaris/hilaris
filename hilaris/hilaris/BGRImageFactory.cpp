#include "BGRImageFactory.h"

BGRImage BGRImageFactory::getFastDebayered(RawImage* raw)
{
	BGRImage image(raw->getWidth(), raw->getHeight());
	
	enum EnBayerOrder order;
	OscCamGetBayerOrder(&order,0,0);
	
	uint8 pTemp[raw->getWidth() * 4];
	
	OscVisDebayerBilinearBGR(image.getDataPtr(), raw->getDataPtr(), raw->getWidth(), raw->getHeight(), pTemp, order);
	
	return image;
}

BGRImage BGRImageFactory::getBilinearDebayered(RawImage* raw)
{
	BGRImage image(raw->getWidth(), raw->getHeight());
	
	return image;
}

BGRImage BGRImageFactory::getDebayered(RawImage* raw)
{
	BGRImage image(raw->getWidth(), raw->getHeight());
	
	enum EnBayerOrder order;
	OscCamGetBayerOrder(&order,0,0);

	OscVisDebayer(raw->getDataPtr(), raw->getWidth(), raw->getHeight(), order, image.getDataPtr());	
	return image;
}

BGRImage BGRImageFactory::getHalfsizeDebayered(RawImage* raw)
{
	BGRImage image(raw->getWidth(), raw->getHeight());
	
	return image;
}
