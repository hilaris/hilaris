#ifndef _THREAD_H_
#define _THREAD_H_

#include <pthread.h>
#include <signal.h>
#include <stdio.h>

class Thread
{
	friend class StreamServer;
	private:
		pthread_t thread;
		static void* dispatch(void *);
		volatile sig_atomic_t cancel;
	protected:
		/**
		 *  @brief This method is the main run method of the Thread. Has to be
		 *  implemented by subinstance.
		 */
		virtual void run() = 0;
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
};

#endif
