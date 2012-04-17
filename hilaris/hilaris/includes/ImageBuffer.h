#ifndef _IMAGE_BUFFER_H_
#define _IMAGE_BUFFER_H_

#include <string.h>

#include "oscar.h"
#include "Mutex.h"

class ImageBuffer
{
	private:
		Mutex mutex;
		int dataSize;
		uint8 bufferSize;
		uint8 start;
		uint8 count;
		uint8* data;
		uint8* currentImg;
	public:
		ImageBuffer(int size, uint8 number);
		~ImageBuffer();
		bool isEmpty();
		void insert(uint8* img);
		uint8* get();
};

#endif
