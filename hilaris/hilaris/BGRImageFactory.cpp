#include "BGRImageFactory.h"

/* deprecated, use raw->debayerFast(BGRImage* image) instead! */
BGRImage BGRImageFactory::getFastDebayered(RawImage* raw)
{
	BGRImage image(raw->getWidth() / 2, raw->getHeight() / 2);
	
	OscVisFastDebayerBGR(&raw->getOscarContext(), &image.getOscarContext());
	
	return image;
}

/* deprecated, use raw->debayerBilinear(BGRImage* image) instead! */
BGRImage BGRImageFactory::getBilinearDebayered(RawImage* raw)
{
	BGRImage image(raw->getWidth(), raw->getHeight());
	
	enum EnBayerOrder order;
	OscCamGetBayerOrder(&order, 0, 0);
	
	uint8 pTemp[raw->getWidth() * 4];
	
	OscVisDebayerBilinearBGR(image.getDataPtr(), raw->getDataPtr(), raw->getWidth(), raw->getHeight(), pTemp, order);
	
	return image;
}

/* deprecated, use raw->debayerStandard(BGRImage* image) instead! */
BGRImage BGRImageFactory::getDebayered(RawImage* raw)
{
	BGRImage image(raw->getWidth(), raw->getHeight());
	
	enum EnBayerOrder order;
	OscCamGetBayerOrder(&order, 0, 0);
	
	OscVisDebayer(raw->getDataPtr(), raw->getWidth(), raw->getHeight(), order, image.getDataPtr());	
	
	return image;
}

/* deprecated, use raw->debayerHalfsize(BGRImage* image) instead! */
BGRImage BGRImageFactory::getHalfsizeDebayered(RawImage* raw)
{
	BGRImage image(raw->getWidth() / 2, raw->getHeight() / 2);
	
	enum EnBayerOrder order;
	OscCamGetBayerOrder(&order, 0, 0);
	
	OscVisDebayerHalfSize(raw->getDataPtr(), raw->getWidth(), raw->getHeight(), order, image.getDataPtr());
	
	return image;
}

BGRImage BGRImageFactory::getFromRGBImage(RGBImage& rgb)
{
	BGRImage bgr(rgb.getWidth(), rgb.getHeight());
	
	for(int i = 0; i < bgr.getHeight(); i ++)
	{
		for(int j = 0; j < bgr.getWidth(); j ++)
		{
			// RGB -> BGR
			// swap colors
			bgr(i, j, BGRImage::RED)   = rgb(i, j, RGBImage::RED);
			bgr(i, j, BGRImage::GREEN) = rgb(i, j, RGBImage::GREEN);
			bgr(i, j, BGRImage::BLUE)  = rgb(i, j, RGBImage::BLUE);
			
		}
	}
	
	return bgr;
}

BGRImage BGRImageFactory::getFromGreyscaleImage(GreyscaleImage& grey)
{
	BGRImage bgr(grey.getWidth(), grey.getHeight());
	
	for(int i = 0; i < bgr.getHeight(); i ++)
	{
		for(int j = 0; j < bgr.getWidth(); j ++)
		{
			bgr(i, j, BGRImage::RED)   = grey(i, j);
			bgr(i, j, BGRImage::GREEN) = grey(i, j);
			bgr(i, j, BGRImage::BLUE)  = grey(i, j);
		}
	}
	
	return bgr;
}

BGRImage BGRImageFactory::getFromBinaryImage(BinaryImage& binary)
{
	BGRImage bgr(binary.getWidth(), binary.getHeight());
	
	for(int i = 0; i < bgr.getHeight(); i ++)
	{
		for(int j = 0; j < bgr.getWidth(); j ++)
		{
			bgr(i, j, BGRImage::RED)   = binary(i, j) == 0 ? 0 : 255;
			bgr(i, j, BGRImage::GREEN) = binary(i, j) == 0 ? 0 : 255;
			bgr(i, j, BGRImage::BLUE)  = binary(i, j) == 0 ? 0 : 255;
		}
	}
	
	return bgr;
}

BGRImage BGRImageFactory::create(uint16 width, uint16 height, uint8 blue, uint16 green, uint16 red)
{
	BGRImage image(width, height);
	
	for(int i = 0; i < image.getHeight(); i++)
	{
		for(int j = 0; j < image.getWidth(); j++)
		{
			image(i, j, BGRImage::BLUE)  = blue;
			image(i, j, BGRImage::GREEN) = green;
			image(i, j, BGRImage::RED)   = red;
		}
	}
	
	return image;
}
