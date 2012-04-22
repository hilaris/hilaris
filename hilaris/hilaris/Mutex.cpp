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
	int rtnval = EINVAL;		// Failure
	
	// This will be a MUTEX done via TRYLOCK and sleep
	// rather than a call to mutex lock
	// This is done to get around the uCinux timing hole
	// in the spin waiting for lock
	
	while( 1 )
	{
		rtnval =  pthread_mutex_trylock(&this->mutex);
		
		//if lock is hold by calling thread unlock it
		if(rtnval == EDEADLK)
			pthread_mutex_unlock(&this->mutex);
			
		if( rtnval == 0 || rtnval == EINVAL )
			break;       // Break on success or bad mutex
												
		usleep( 50 );    // Sleep for 50 usec
	}
	return( rtnval==0 );
}
