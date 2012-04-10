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


// @TODO some bugs here.. it seems that the greyscale image out of the binary image has all its greyscales, not just 1 and 0, test that
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

GreyscaleImage GreyscaleImageFactory::getFromBGRImage(BGRImage& bgr)
{
	GreyscaleImage image(bgr.getWidth(), bgr.getHeight());
	
	OscVisBGR2Grey(&bgr.getOscarContext(), &image.getOscarContext());
	
	return image;
}

GreyscaleImage GreyscaleImageFactory::getFromRGBImage(RGBImage& rgb)
{
	BGRImage bgr = BGRImageFactory::getFromRGBImage(rgb);
	
	return GreyscaleImageFactory::getFromBGRImage(bgr);
}

GreyscaleImage GreyscaleImageFactory::create(uint16 width, uint16 height, uint8 color)
{
	GreyscaleImage image(width, height);
	
	for(int i = 0; i < image.getHeight(); i++)
	{
		for(int j = 0; j < image.getWidth(); j++)
		{
			image(i, j) = color;
		}
	}
	
	return image;
}
