#include "BGRImageFactory.h"

BGRImage BGRImageFactory::getFastDebayered(RawImage* raw)
{
	BGRImage image(raw->getWidth() / 2, raw->getHeight() / 2);
	
	OscVisFastDebayerBGR(&raw->getOscarContext(), &image.getOscarContext());
	
	return image;
}

BGRImage BGRImageFactory::getBilinearDebayered(RawImage* raw)
{
	BGRImage image(raw->getWidth(), raw->getHeight());
	
	enum EnBayerOrder order;
	OscCamGetBayerOrder(&order, 0, 0);
	
	uint8 pTemp[raw->getWidth() * 4];
	
	OscVisDebayerBilinearBGR(image.getDataPtr(), raw->getDataPtr(), raw->getWidth(), raw->getHeight(), pTemp, order);
	
	return image;
}

BGRImage BGRImageFactory::getDebayered(RawImage* raw)
{
	OscLog(DEBUG, "Create BGR Image w %d / h %d\n", raw->getWidth(), raw->getHeight());
	BGRImage image(raw->getWidth(), raw->getHeight());
	OscLog(DEBUG, "Before Bayerorder\n");
	enum EnBayerOrder order;
	OscCamGetBayerOrder(&order, 0, 0);
	
	OscLog(DEBUG, "Before debayer %p, %d, %d, %p\n", raw->getDataPtr(), raw->getWidth(), raw->getHeight(), image.getDataPtr());
	OscVisDebayer(raw->getDataPtr(), raw->getWidth(), raw->getHeight(), order, image.getDataPtr());	
	
	OscLog(DEBUG, "after debayer\n");
	return image;
}

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
