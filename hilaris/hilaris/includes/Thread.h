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
		virtual void run() = 0;
	public:
		Thread();
		virtual ~Thread();
		void start();
		void join();
		void stop();
};

#endif
