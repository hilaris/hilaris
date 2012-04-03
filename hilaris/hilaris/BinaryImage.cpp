#include "BinaryImage.h"
#include "GreyscaleImage.h"
#include "GreyscaleImageFactory.h"

#include <string.h>

BinaryImage::BinaryImage(uint16 width, uint16 height)
{
	this->width = width;
	this->height = height;
	
	this->setOscarContext();
}

EnOscPictureType BinaryImage::getType()
{
	return OSC_PICTURE_BINARY;
}

uint8* BinaryImage::getDataPtr()
{
	return this->data;
}

void BinaryImage::save(char* path, enum ImageEncoding enc)
{
	GreyscaleImage grey = GreyscaleImageFactory::getFromBinaryImage(*this);
	
	this->saveContext(grey.getOscarContext(), path);
}

uint8& BinaryImage::pixel(uint16 x, uint16 y)
{
	return this->data[x * this->getWidth() + y];
}

uint8& BinaryImage::operator()(const uint16 x, const uint16 y)
{
    return this->pixel(x, y);
}

bool BinaryImage::erode(struct OSC_VIS_STREL *strel, uint8 repetitions)
{
	OSC_ERR err;
	OSC_PICTURE picIn = this->getOscarContext();
	OSC_PICTURE picOut;
	
	uint8 outData[this->getWidth() * this->getHeight()];
	
	picOut.data = outData;
	uint8 pTemp[this->getWidth() * this->getHeight()];
	
	if((err = OscVisErode(&picIn, &picOut, pTemp, strel, repetitions)) != SUCCESS)
	{
		return false;
	}
	
	memcpy(this->getDataPtr(), picOut.data, this->getWidth() * this->getHeight());
	
	return true;
}

bool BinaryImage::dilate(struct OSC_VIS_STREL *strel, uint8 repetitions)
{
	OSC_ERR err;
	OSC_PICTURE picIn = this->getOscarContext();
	OSC_PICTURE picOut;
	
	uint8 outData[this->getWidth() * this->getHeight()];
	
	picOut.data = outData;
	uint8 pTemp[this->getWidth() * this->getHeight()];
	
	if((err = OscVisDilate(&picIn, &picOut, pTemp, strel, repetitions)) != SUCCESS)
	{
		return false;
	}
	
	memcpy(this->getDataPtr(), picOut.data, this->getWidth() * this->getHeight());
	
	return true;
}
