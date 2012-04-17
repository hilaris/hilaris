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
		int bufferSize;
		int start;
		int count;
		uint8* data;
		uint8* currentImg;
	public:
		ImageBuffer(int dataSize, int bufferSize);
		~ImageBuffer();
		bool isEmpty();
		void insert(uint8* img);
		uint8* get();
};

#endif
