#include "BGRImage.h"

BGRImage::BGRImage(uint16 width, uint16 height)
{
	OscLog(DEBUG, "Creating BGRImage width: %d, height: %d\n", width, height);
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

uint8& BGRImage::pixel(uint16 x, uint16 y, enum BGRImage::Pixel component)
{
	return this->data[x * this->getWidth() * 3 + y * 3 + component];
}

uint8& BGRImage::operator()(const uint16 x, const uint16 y, enum BGRImage::Pixel component)
{
	return this->pixel(x, y, component);
}
