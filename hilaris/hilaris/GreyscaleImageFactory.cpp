#include "GreyscaleImageFactory.h"

GreyscaleImage GreyscaleImageFactory::getFastDebayered(RawImage* raw)
{
	GreyscaleImage image(raw->getWidth() / 2, raw->getHeight() / 2);
	
	OscVisFastDebayerGrey(&raw->getOscarContext(), &image.getOscarContext());
	
	return image;
}

GreyscaleImage GreyscaleImageFactory::getVectorDebayered(RawImage* raw)
{
	GreyscaleImage image(raw->getWidth() / 2, raw->getHeight() / 2);
	
	OscVisVectorDebayerGrey(&raw->getOscarContext(), &image.getOscarContext());
	
	return image;
}

GreyscaleImage GreyscaleImageFactory::getHalfsizeDebayered(RawImage* raw)
{
	GreyscaleImage image(raw->getWidth() / 2, raw->getHeight() / 2);
	
	enum EnBayerOrder order;
	OscCamGetBayerOrder(&order, 0, 0);
	
	OscVisDebayerGreyscaleHalfSize(raw->getDataPtr(), raw->getWidth(), raw->getHeight(), order, image.getDataPtr());
	
	return image;
}
