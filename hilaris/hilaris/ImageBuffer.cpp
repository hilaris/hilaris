#include "ImageBuffer.h"
#include "Debug.h"

ImageBuffer::ImageBuffer(int dataSize, int bufferSize)
{
	this->dataSize = dataSize;
	this->bufferSize = bufferSize;
	
	this->count = 0;
	this->start = 0;
	
	Debug::log("count %d start %d\n", this->count, this->start);
	
	this->data = new uint8[this->dataSize * this->bufferSize];
	Debug::log("count %d start %d\n", this->count, this->start);
	this->currentImg = new uint8[this->dataSize];
	
	Debug::log("count %d start %d\n", this->count, this->start);
	Debug::log("count %p start %p data %p\n", &this->count, &this->start, this->data);
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
	int c = this->count;
	this->mutex.unlock();
	
	return (c <= 0);
}

void ImageBuffer::insert(uint8* img)
{
	this->mutex.lock();
	{
		int end = (this->start - this->count) % this->bufferSize;
		Debug::log("start %d count %d\n", this->start, this->count);
		memcpy(&this->data[end*this->dataSize], img, this->dataSize);
	
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
		Debug::log("position insert %d\n", this->start*this->dataSize);
		memcpy(this->currentImg, &this->data[this->start*this->dataSize], this->dataSize);
		
		this->start = (this->start + 1) % this->bufferSize;
		this->count--;
	}
	this->mutex.unlock();
	
	OscLog(DEBUG, "image data %d %d %d\n", this->currentImg[100], this->currentImg[300], this->currentImg[10000]);
	
	return this->currentImg;
}
