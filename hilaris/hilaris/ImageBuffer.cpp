#include "ImageBuffer.h"
#include "Debug.h"

ImageBuffer::ImageBuffer(int dataSize, int bufferSize)
{
	this->dataSize = dataSize;
	this->bufferSize = bufferSize;
	
	this->count = 0;
	this->start = 0;
		
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
	int c = 0;
	
	this->mutex.lock();
	{
		c = this->count;
		this->mutex.unlock();
	}
	
	return (c <= 0);
}

void ImageBuffer::insert(uint8* img)
{
	this->mutex.lock();
	{
		int end = (this->start + this->count) % this->bufferSize;
		memcpy(&this->data[end * this->dataSize], img, this->dataSize);
	
		if(this->count == this->bufferSize)
		{
			this->start = (this->start + 1) % this->bufferSize;
			printf("full\n");
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
		memcpy(this->currentImg, &this->data[this->start * this->dataSize], this->dataSize);
		
		this->start = (this->start + 1) % this->bufferSize;
		this->count--;
	}
	this->mutex.unlock();
	
	return this->currentImg;
}
