#ifndef _MUTEX_H_
#define _MUTEX_H_

#include <pthread.h>
#include <errno.h>
#include <unistd.h>

/**
 *  @brief A class based Mutex implementation.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since April 2012
 */
class Mutex
{
	public:
	
		Mutex();
		~Mutex();
		
		/**
		 *  @brief Locks this Mutex.
		 */
		void lock();
		
		/**
		 *  @brief Unlocks this Mutex.
		 */
		void unlock();
		
		/**
		 *  @brief Try to lock this Mutex.
		 *  @return A boolean wheter you can lock this Mutex or not.
		 */
		bool trylock();
		
	private:
	
		pthread_mutex_t mutex;
};

#endif
