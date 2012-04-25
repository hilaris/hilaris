#ifndef _THREAD_H_
#define _THREAD_H_

#include <pthread.h>
#include <signal.h>
#include <stdio.h>

/**
 *  @brief Thread base class.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 */
class Thread
{
	friend class StreamServer;
		
	public:
		/**
		 *  @brief Create a Thread. This is a constructor.
		 */
		Thread();
		
		/**
		 *  @brief Destructor for a specific Thread. Has to be implemented.
		 */
		virtual ~Thread();
		
		/**
		 *  @brief Start the Thread.
		 */
		void start();
		
		/**
		 *  @brief Wait for this Thread to be finsihed.
		 */
		void join();
		
		/**
		 * @brief Stop this Thread.
		 */
		void stop();
		
	protected:
		/**
		 *  @brief This method is the main run method of the Thread. Has to be
		 *  implemented by subinstance.
		 */
		virtual void run() = 0;
	
	private:
		pthread_t thread;
		static void* dispatch(void *);
		volatile sig_atomic_t cancel;
};

#endif
