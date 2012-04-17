#include "Mutex.h"

Mutex::Mutex()
{
	pthread_mutex_init(&this->mutex, 0);
}

Mutex::~Mutex()
{
	pthread_mutex_destroy(&this->mutex);
}

void Mutex::lock()
{
	pthread_mutex_lock(&this->mutex);
}

void Mutex::unlock()
{
	pthread_mutex_unlock(&this->mutex);
}

bool Mutex::trylock()
{
	return (pthread_mutex_trylock(&this->mutex) == 0);
}
