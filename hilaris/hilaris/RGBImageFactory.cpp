#include "RGBImageFactory.h"

RGBImage RGBImageFactory::getFastDebayered(RawImage* raw)
{
	RGBImage image(raw->getWidth() / 2, raw->getHeight() / 2);
	
	OscVisFastDebayerRGB(&raw->getOscarContext(), &image.getOscarContext());
	
	return image;
}

RGBImage RGBImageFactory::getFromBGRImage(BGRImage& bgr)
{
	RGBImage rgb(rgb.getWidth(), rgb.getHeight());
	
	for(int i = 0; i < rgb.getHeight(); i ++)
	{
		for(int j = 0; j < rgb.getWidth(); j ++)
		{
			// BGR -> RGB
			// swap colors
			rgb(i, j, RGBImage::RED)   = bgr(i, j, BGRImage::RED);
			rgb(i, j, RGBImage::GREEN) = bgr(i, j, BGRImage::GREEN);
			rgb(i, j, RGBImage::BLUE)  = bgr(i, j, BGRImage::BLUE);
			
		}
	}
	
	return rgb;
}

RGBImage RGBImageFactory::getFromGreyscaleImage(GreyscaleImage& grey)
{
	RGBImage rgb(grey.getWidth(), grey.getHeight());
	
	for(int i = 0; i < rgb.getHeight(); i ++)
	{
		for(int j = 0; j < rgb.getWidth(); j ++)
		{
			rgb(i, j, RGBImage::RED)   = grey(i, j);
			rgb(i, j, RGBImage::GREEN) = grey(i, j);
			rgb(i, j, RGBImage::BLUE)  = grey(i, j);
		}
	}
	
	return rgb;
}

RGBImage RGBImageFactory::getFromBinaryImage(BinaryImage& binary)
{
	RGBImage rgb(binary.getWidth(), binary.getHeight());
	
	for(int i = 0; i < rgb.getHeight(); i ++)
	{
		for(int j = 0; j < rgb.getWidth(); j ++)
		{
			rgb(i, j, RGBImage::RED)   = binary(i, j) == 0 ? 0 : 255;
			rgb(i, j, RGBImage::GREEN) = binary(i, j) == 0 ? 0 : 255;
			rgb(i, j, RGBImage::BLUE)  = binary(i, j) == 0 ? 0 : 255;
		}
	}
	
	return rgb;
}


RGBImage RGBImageFactory::create(uint16 width, uint16 height, uint8 blue, uint16 green, uint16 red)
{
	RGBImage image(width, height);
	
	for(int i = 0; i < image.getHeight(); i++)
	{
		for(int j = 0; j < image.getWidth(); j++)
		{
			image(i, j, RGBImage::GREEN) = green;
			image(i, j, RGBImage::RED)   = red;
			image(i, j, RGBImage::BLUE)  = blue;
		}
	}
	
	return image;
}
