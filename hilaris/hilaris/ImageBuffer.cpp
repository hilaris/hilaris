#include "ImageBuffer.h"

ImageBuffer::ImageBuffer(int dataSize, uint8 bufferSize)
{
	this->dataSize = dataSize;
	this->bufferSize = bufferSize;
	
	this->data = new uint8[this->dataSize * this->bufferSize];
	this->currentImg = new uint8[this->dataSize];
}

ImageBuffer::~ImageBuffer()
{
	this->mutex.lock();
	delete[] this->data;
	this->mutex.unlock();
}

bool ImageBuffer::isEmpty()
{
	this->mutex.lock();
	uint8 c = this->count;
	this->mutex.unlock();
	
	return (c == 0);
}

void ImageBuffer::insert(uint8* img)
{
	this->mutex.lock();
	{
		int end = (this->start - this->count) % this->bufferSize;
	
		memcpy(&this->data[end], img, this->dataSize);
	
		if(this->count == this->bufferSize)
		{
			this->start = (this->start + 1) % this->bufferSize;
		}
		else
		{
			this->count++;
		}
	}
	this->mutex.unlock();
}

uint8* ImageBuffer::get()
{
	this->mutex.lock();
	{
		memcpy(this->currentImg, &this->data[this->start], this->dataSize);
		
		this->start = (this->start + 1) % this->bufferSize;
		this->count--;
	}
	this->mutex.unlock();
	
	OscLog(DEBUG, "image data %d %d %d\n", this->currentImg[100], this->currentImg[300], this->currentImg[10000]);
	
	return this->currentImg;
}
