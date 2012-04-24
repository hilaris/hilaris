#include "BinaryImage.h"

BinaryImage::BinaryImage(uint16 width, uint16 height)
{
	this->width = width;
	this->height = height;
	
	this->setOscarContext();
}

BinaryImage::BinaryImage(uint16 width, uint16 height, uint8 color)
{
	this->width = width;
	this->height = height;
	
	for(int i = 0; i < this->getHeight(); i++)
	{
		for(int j = 0; j < this->getWidth(); j++)
		{
			this->pixel(i, j) = color && 1;
		}
	}
	
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

void BinaryImage::invert()
{
	for(int i = 0; i < this->getHeight(); i ++)
	{
		for(int j = 0; j < this->getWidth(); j ++)
		{
			this->pixel(i, j) = (uint8)(!this->pixel(i, j));
		}
	}
	
	this->setInvertedBackground(!this->getInvertedBackground());
}

void BinaryImage::setInvertedBackground(bool set)
{
	this->invertedBackground = set;
}

bool BinaryImage::getInvertedBackground()
{
	return this->invertedBackground;
}

uint8& BinaryImage::pixel(uint16 x, uint16 y)
{
	return this->data[x * this->getWidth() + y];
}

uint8& BinaryImage::operator()(const uint16 x, const uint16 y)
{
    return this->pixel(x, y);
}

BinaryImage BinaryImage::operator-(BinaryImage& in)
{
	BinaryImage out(this->getWidth(), this->getHeight());
	
	for(int i = 0; i < this->getHeight(); i ++)
	{
		for(int j = 0; j < this->getWidth(); j ++)
		{
			// XOR
			bool a = this->pixel(i, j) > 0;
			bool b = in.pixel(i, j)    > 0;
			
			// Result
			bool r = (a && !b) || (!a && b);
			
			out(i, j) = r ? 1 : 0;
		} 
	}
	
	return out;
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


OSC_VIS_REGIONS& BinaryImage::getRegions()
{
	return this->regions;
}
		
bool BinaryImage::label()
{
	OSC_ERR err;
	
	if((err = OscVisLabelBinary(&this->getOscarContext(), &this->getRegions())) != SUCCESS)
	{
		return false;
	}
	
	if((err = OscVisGetRegionProperties(&this->getRegions())) != SUCCESS)
	{
		return false;
	}
	
	return true;
}

bool BinaryImage::drawCentroid()
{
	OSC_ERR err;
	
	return (err = OscVisDrawCentroidMarkers(&this->getOscarContext(), &this->getRegions())) != SUCCESS;
 
}

bool BinaryImage::drawBoundingBox()
{
	OSC_ERR err;
	
	return (err = OscVisDrawBoundingBox(&this->getOscarContext(), &this->getRegions())) != SUCCESS;
}

bool BinaryImage::sobel(uint8 exp)
{
	OSC_ERR err;
	uint8 outData[this->getWidth() * this->getHeight()];
	
	if((err = OscVisSobel(this->getDataPtr(), outData, this->getWidth(), this->getHeight(), exp)) != SUCCESS)
	{
		return false;
	}
	
	memcpy(this->getDataPtr(), outData, this->getWidth() * this->getHeight());
	
	return true;
}

void BinaryImage::subtract(BinaryImage* img)
{
	for(int i = 0; i < this->getHeight(); i ++)
	{
		for(int j = 0; j < this->getWidth(); j ++)
		{
			// XOR
			bool a = this->pixel(i, j) > 0;
			bool b = img->pixel(i, j)  > 0;
			
			// Result
			bool r = (a && !b) || (!a && b);
			
			(*this)(i, j) = r ? 255 : 0;
		} 
	}
}
