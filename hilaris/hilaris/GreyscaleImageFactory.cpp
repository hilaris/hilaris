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

GreyscaleImage GreyscaleImageFactory::getFromBinaryImage(BinaryImage& binary)
{
	GreyscaleImage image(binary.getWidth(), binary.getHeight());
	
	for(int i = 0; i < image.getHeight(); i++)
	{
		for(int j = 0; j < image.getWidth(); j++)
		{
			uint8 px = binary.pixel(i, j);
			
			// set with new value
			image(i, j) = px * 255;
		}
	}
	
	return image;
}
