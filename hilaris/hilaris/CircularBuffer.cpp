#include "CircularBuffer.h"

template<class T>
CircularBuffer<T>::CircularBuffer(int s)
{
	this->size = s + 1;
	this->start = 0;
	this->end = 0;
	this->elements = (T *)calloc(this->size, sizeof(T));
}

template<class T>
CircularBuffer<T>::~CircularBuffer()
{
	free(this->elements);
}

template<class T>
bool CircularBuffer<T>::isFull()
{
	return (this->end + 1) % this->size == this->start;
}

template<class T>
bool CircularBuffer<T>::isEmpty()
{
	return this->end == this->start;
}

template<class T>
bool CircularBuffer<T>::insert(const T& t)
{
	memcpy(&this->elements[this->end], &t, sizeof(T));
	this->end = (this->end + 1) % this->size;
	
    if (this->end == this->start)
    {
		this->start = (this->start + 1) % this->size;
	}
	return true;
}

template<class T>	
T CircularBuffer<T>::read()
{
	T t = this->elements[this->start];
	this->start = (this->start + 1) % this->size;
	
	return t;
}
