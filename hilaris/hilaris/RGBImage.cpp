#include "RGBImage.h"

RGBImage::RGBImage(uint16 width, uint16 height)
{
	this->width = width;
	this->height = height;
	
	this->setOscarContext();
}

RGBImage::RGBImage(uint16 width, uint16 height, uint32 color)
{
	this->width = width;
	this->height = height;
	
 	for(int i = 0; i < this->getHeight(); i++)
	{
		for(int j = 0; j < this->getWidth(); j++)
		{
			this->pixel(i, j, RGBImage::GREEN) = (color & 0xFF0000) >> 16;
			this->pixel(i, j, RGBImage::RED)   = (color & 0x00FF00) >> 8;
			this->pixel(i, j, RGBImage::BLUE)  = (color & 0x0000FF);
		}
	}
	
	this->setOscarContext();
}

RGBImage::RGBImage(uint16 width, uint16 height, uint8 red, uint16 green, uint16 blue)
{
	this->width = width;
	this->height = height;
	
	for(int i = 0; i < this->getHeight(); i++)
	{
		for(int j = 0; j < this->getWidth(); j++)
		{
			this->pixel(i, j, RGBImage::GREEN) = green;
			this->pixel(i, j, RGBImage::RED)   = red;
			this->pixel(i, j, RGBImage::BLUE)  = blue;
		}
	}
	
	this->setOscarContext();
}

EnOscPictureType RGBImage::getType()
{
	return OSC_PICTURE_RGB_24;
}

uint8* RGBImage::getDataPtr()
{
	return this->data;
}

uint8& RGBImage::pixel(uint16 x, uint16 y, enum RGBImage::Pixel component)
{
	return this->data[x * this->getWidth() * 3 + y * 3 + component];
}

uint8& RGBImage::operator()(const uint16 x, const uint16 y, enum RGBImage::Pixel component)
{
	return this->pixel(x, y, component);
}

void RGBImage::save(char* path, enum ImageEncoding enc)
{
	BGRImage bgr = BGRImageFactory::getFromRGBImage(*this);
	
	this->saveContext(bgr.getOscarContext(), path);
}
