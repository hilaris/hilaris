#include "BGRImage.h"

BGRImage::BGRImage(uint16 width, uint16 height)
{
	this->width = width;
	this->height = height;
	
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

void BGRImage::pixel(uint16 x, uint16 y, struct BGRPixel& pixel)
{
	pixel.blue  = this->data[x * this->getWidth() * 3 + y * 3];
	pixel.green = this->data[x * this->getWidth() * 3 + y * 3 + 1];
	pixel.red   = this->data[x * this->getWidth() * 3 + y * 3 + 1 + 1];
}

BGRPixel& BGRImage::operator()(const uint16 x, const uint16 y, struct BGRPixel& pixel)
{
    this->pixel(x, y, pixel);
    
    return pixel;
}

uint8& BGRImage::component(uint16 x, uint16 y)
{
	return this->data[x * this->getWidth() * 3 + y];
}

uint8& BGRImage::operator()(const uint16 x, const uint16 y)
{
    return this->component(x, y);
}

