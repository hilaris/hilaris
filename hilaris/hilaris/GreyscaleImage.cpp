#include "GreyscaleImage.h"
#include <string.h>

GreyscaleImage::GreyscaleImage(uint16 width, uint16 height)
{
	this->hist = NULL;
	this->width = width;
	this->height = height;
	
	this->setOscarContext();
}

GreyscaleImage::~GreyscaleImage()
{
	if(this->hist != NULL)
	{
		delete this->hist;
	}
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


bool GreyscaleImage::filter(struct OSC_VIS_FILTER_KERNEL *kernel)
{
	OSC_ERR err;
	OSC_PICTURE picIn = this->getOscarContext();
	OSC_PICTURE picOut;
	
	uint8 outData[this->getWidth() * this->getHeight()];
	
	picOut.data = outData;
	uint8 pTemp[this->getWidth() * this->getHeight()];
	
	if((err = OscVisFilter2D(&picIn, &picOut, pTemp, kernel)) != SUCCESS)
	{
		return false;
	}
	
	memcpy(this->getDataPtr(), picOut.data, this->getWidth() * this->getHeight());
	
	return true;
}

bool GreyscaleImage::sobel(uint8 exp)
{
	OSC_ERR err;
	printf("%d x %d\n", this->getWidth() , this->getHeight());
	uint8 outData[this->getWidth() * this->getHeight()];
	
	if((err = OscVisSobel(this->getDataPtr(), outData, this->getWidth(), this->getHeight(), exp)) != SUCCESS)
	{
		return false;
	}
	
	memcpy(this->getDataPtr(), outData, this->getWidth() * this->getHeight());
	
	return true;
}

Histogram* GreyscaleImage::histogram()
{
	if(this->hist == NULL)
	{
		this->hist = new Histogram(this);
		this->hist->init();
	}
	
	return this->hist;
}
