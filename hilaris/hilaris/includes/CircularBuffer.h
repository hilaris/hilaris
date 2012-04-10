#ifndef _CIRCULAR_BUFFER_H_
#define _CIRCULAR_BUFFER_H_

#include "Hilaris.h"

#include <malloc.h>

template <class T>
class CircularBuffer
{
	private:
		int size;
		int start;
		int end;
		T* elements;
	public:
		CircularBuffer(int s);
		~CircularBuffer();
		bool isFull();
		bool isEmpty();
		bool insert(const T& t);
		T read();	
};

#endif 
