#include "RGBImage.h"

RGBImage::RGBImage(uint16 width, uint16 height)
{
	this->width = width;
	this->height = height;
	
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
