#ifndef _MUTEX_H_
#define _MUTEX_H_

#include <pthread.h>

class Mutex
{
	private:
		pthread_mutex_t mutex;
	public:
		Mutex();
		~Mutex();
		void lock();
		void unlock();
		bool trylock();
};

#endif
