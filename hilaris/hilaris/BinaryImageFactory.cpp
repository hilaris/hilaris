#include "BinaryImageFactory.h"

BinaryImage BinaryImageFactory::getFastDebayered(RawImage* raw, uint8 threshold, bool darkIsForeground)
{
	GreyscaleImage image = GreyscaleImageFactory::getFastDebayered(raw);
	
	return BinaryImageFactory::getFromGreyscaleImage(image, threshold, darkIsForeground);
}

BinaryImage BinaryImageFactory::getVectorDebayered(RawImage* raw, uint8 threshold, bool darkIsForeground)
{
	GreyscaleImage image = GreyscaleImageFactory::getVectorDebayered(raw);
	
	return BinaryImageFactory::getFromGreyscaleImage(image, threshold, darkIsForeground);
}

BinaryImage BinaryImageFactory::getHalfsizeDebayered(RawImage* raw, uint8 threshold, bool darkIsForeground)
{
	GreyscaleImage image = GreyscaleImageFactory::getHalfsizeDebayered(raw);
	
	return BinaryImageFactory::getFromGreyscaleImage(image, threshold, darkIsForeground);
}

BinaryImage BinaryImageFactory::getFromGreyscaleImage(GreyscaleImage& grey, uint8 threshold, bool darkIsForeground)
{
	BinaryImage image(grey.getWidth(), grey.getHeight());
	
	OscVisGrey2BW(&grey.getOscarContext(), &image.getOscarContext(), threshold, darkIsForeground);
	
	return image;
}

BinaryImage BinaryImageFactory::getFromBGRImage(BGRImage& bgr, uint8 threshold, bool darkIsForeground)
{
	BinaryImage image(bgr.getWidth(), bgr.getHeight());
	
	OscVisBGR2BW(&bgr.getOscarContext(), &image.getOscarContext(), threshold, darkIsForeground);
	
	return image;
}

BinaryImage BinaryImageFactory::getFromRGBImage(RGBImage& rgb, uint8 threshold, bool darkIsForeground)
{
	BGRImage bgr = BGRImageFactory::getFromRGBImage(rgb);
	
	return BinaryImageFactory::getFromBGRImage(bgr, threshold, darkIsForeground);
}


BinaryImage BinaryImageFactory::create(uint16 width, uint16 height, uint8 color)
{
	BinaryImage image(width, height);
	
	for(int i = 0; i < image.getHeight(); i++)
	{
		for(int j = 0; j < image.getWidth(); j++)
		{
			image(i, j) = color && 1;
		}
	}
	
	return image;
}
