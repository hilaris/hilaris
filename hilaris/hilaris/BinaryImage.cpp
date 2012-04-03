#include "BinaryImage.h"

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

/*
bool BinaryImage::erode(struct OSC_VIS_STREL *strel, uint8 repetitions)
{
	OSC_ERR err;
	OSC_PICTURE picIn = this->getOscarContext();
	OSC_PICTURE picOut;
	uint8 outData[this->width * this->height * 3];
	
	picOut.data = outData;
	uint8 pTemp[this->width * this->height * 3];
	
	if((err = OscVisErode(&picIn, &picOut, pTemp, strel, repetitions)) != SUCCESS)
	{
		return false;
	}
	
	memcpy(this->data, picOut.data, this->width * this->height * sizeof(uint8));
	
	return true;
}

bool BinaryImage::dilate(struct OSC_VIS_STREL *strel, uint8 repetitions)
{
	OSC_ERR err;
	OSC_PICTURE picIn = this->getOscarContext();
	OSC_PICTURE picOut;
	uint8 outData[this->width * this->height * 3];
	
	picOut.data = outData;
	uint8 pTemp[this->width * this->height * 3];
	
	if((err = OscVisDilate(&picIn, &picOut, pTemp, strel, repetitions)) != SUCCESS)
	{
		return false;
	}
	
	memcpy(this->data, picOut.data, this->width * this->height * sizeof(uint8));
	
	return true;
}
*/
