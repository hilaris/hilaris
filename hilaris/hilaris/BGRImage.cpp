#include "BGRImage.h"

BGRImage::BGRImage(uint16 width, uint16 height)
{
	this->width = width;
	this->height = height;
	
	this->setOscarContext();
}

BGRImage::BGRImage(uint16 width, uint16 height, uint32 color)
{
	this->width = width;
	this->height = height;
	
 	for(int i = 0; i < this->getHeight(); i++)
	{
		for(int j = 0; j < this->getWidth(); j++)
		{
			this->pixel(i, j, BGRImage::BLUE)  = (color & 0x0000FF) >> 16;
			this->pixel(i, j, BGRImage::GREEN) = (color & 0xFF0000) >> 8;
			this->pixel(i, j, BGRImage::RED)   = (color & 0x00FF00);
		}
	}
	
	this->setOscarContext();
}

BGRImage::BGRImage(uint16 width, uint16 height, uint8 red, uint16 green, uint16 blue)
{
	this->width = width;
	this->height = height;
	
	for(int i = 0; i < this->getHeight(); i++)
	{
		for(int j = 0; j < this->getWidth(); j++)
		{
			this->pixel(i, j, BGRImage::BLUE)  = blue;
			this->pixel(i, j, BGRImage::GREEN) = green;
			this->pixel(i, j, BGRImage::RED)   = red;
		}
	}
	
	this->setOscarContext();
}

EnOscPictureType BGRImage::getType()
{
	return OSC_PICTURE_BGR_24;
}

uint8* BGRImage::getDataPtr()
{
	return this->data;
}

uint8& BGRImage::pixel(uint16 x, uint16 y, enum BGRImage::Pixel component)
{
	return this->data[x * this->getWidth() * 3 + y * 3 + component];
}

uint8& BGRImage::operator()(const uint16 x, const uint16 y, enum BGRImage::Pixel component)
{
	return this->pixel(x, y, component);
}
