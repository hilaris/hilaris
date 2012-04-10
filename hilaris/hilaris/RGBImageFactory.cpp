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
			image(i, j, GREEN) = green;
			image(i, j, RED)   = red;
			image(i, j, BLUE)  = blue;
		}
	}
	
	return image;
}
