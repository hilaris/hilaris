#include "BinaryImageFactory.h"
#include "GreyscaleImageFactory.h"

BinaryImage BinaryImageFactory::getFastDebayered(RawImage* raw, uint8 thresold, bool darkIsForeground)
{
	GreyscaleImage image = GreyscaleImageFactory::getFastDebayered(raw);
	
	return BinaryImageFactory::getFromGreyscaleImage(image, thresold, darkIsForeground);
}

BinaryImage BinaryImageFactory::getVectorDebayered(RawImage* raw, uint8 thresold, bool darkIsForeground)
{
	GreyscaleImage image = GreyscaleImageFactory::getVectorDebayered(raw);
	
	return BinaryImageFactory::getFromGreyscaleImage(image, thresold, darkIsForeground);
}

BinaryImage BinaryImageFactory::getHalfsizeDebayered(RawImage* raw, uint8 thresold, bool darkIsForeground)
{
	GreyscaleImage image = GreyscaleImageFactory::getHalfsizeDebayered(raw);
	
	return BinaryImageFactory::getFromGreyscaleImage(image, thresold, darkIsForeground);
}

BinaryImage BinaryImageFactory::getFromGreyscaleImage(GreyscaleImage& grey, uint8 thresold, bool darkIsForeground)
{
	BinaryImage image(grey.getWidth(), grey.getHeight());
	
	OscVisGrey2BW(&grey.getOscarContext(), &image.getOscarContext(), thresold, darkIsForeground);
	
	return image;
}

/*
 *	@todo add correct error handling, like whatif width is not dividable by 4 etc.
 */
 
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
