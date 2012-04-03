#include "GreyscaleImage.h"

GreyscaleImage::GreyscaleImage(uint16 width, uint16 height)
{
	this->width = width;
	this->height = height;
	
	this->setOscarContext();
}

EnOscPictureType GreyscaleImage::getType()
{
	return OSC_PICTURE_GREYSCALE;
}

uint8* GreyscaleImage::getDataPtr()
{
	return this->data;
}

uint8& GreyscaleImage::pixel(uint16 x, uint16 y)
{
	return this->data[x * this->getWidth() + y];
}

uint8& GreyscaleImage::operator()(const uint16 x, const uint16 y)
{
    return this->pixel(x, y);
}

/*

bool GreyscaleImage::filter(struct OSC_VIS_FILTER_KERNEL *kernel)
{
	OSC_ERR err;
	OSC_PICTURE picIn = this->getOscarContext();
	OSC_PICTURE picOut;
	uint8 outData[this->width * this->height * 3];
	
	picOut.data = outData;
	uint8 pTemp[this->width * this->height * 3];
	
	if((err = OscVisFilter2D(&picIn, &picOut, pTemp, kernel)) != SUCCESS)
	{
		return false;
	}
	
	memcpy(this->data, picOut.data, this->width * this->height * sizeof(uint8));
	
	return true;
}
*/
