#include "ImageBuffer.h"
#include "Debug.h"

ImageBuffer::ImageBuffer(int dataSize, int bufferSize)
{
	//printf("%d\n", dataSize);
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
	printf("before lock insert\n");
	this->mutex.lock();
	{
		printf("after lock insert\n");
		int end = (this->start + this->count) % this->bufferSize;
		//printf("start %d count %d insert %d\n", this->start, this->count, end*this->dataSize);
		memcpy(&this->data[end*this->dataSize], img, this->dataSize);
	
		if(this->count == this->bufferSize)
		{
			this->start = (this->start + 1) % this->bufferSize;
			printf("full\n");
		}
		else
		{
			this->count++;
		}
		
		printf("before unlock insert\n");
		this->mutex.unlock();
		printf("after unlock insert\n");
	}
}

uint8* ImageBuffer::get()
{
	printf("before lock get\n");
	this->mutex.lock();
	{
		printf("after lock get\n");
		//printf("position insert %d\n", this->start*this->dataSize);
		memcpy(this->currentImg, &this->data[this->start*this->dataSize], this->dataSize);
		
		this->start = (this->start + 1) % this->bufferSize;
		this->count--;
		
		printf("before unlock get\n");
		this->mutex.unlock();
		printf("after unlock get\n");
	}
	
	
	return this->currentImg;
}
