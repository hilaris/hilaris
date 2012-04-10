#include "RGBImageFactory.h"

RGBImage RGBImageFactory::getFastDebayered(RawImage* raw)
{
	RGBImage image(raw->getWidth() / 2, raw->getHeight() / 2);
	
	OscVisFastDebayerRGB(&raw->getOscarContext(), &image.getOscarContext());
	
	return image;
}

RGBImage RGBImageFactory::create(uint16 width, uint16 height, uint8 blue, uint16 green, uint16 red)
{
	RGBImage image(width, height);
	
	for(int i = 0; i < image.getHeight(); i++)
	{
		for(int j = 0; j < image.getWidth(); j++)
		{
			image(i, j, RGB_GREEN) = green;
			image(i, j, RGB_RED)   = red;
			image(i, j, RGB_BLUE)  = blue;
		}
	}
	
	return image;
}
