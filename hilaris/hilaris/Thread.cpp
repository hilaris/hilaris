#include "Thread.h"

Thread::Thread():cancel(0){}

Thread::~Thread(){}

void* Thread::dispatch(void* ptr)
{
	if(!ptr) return 0;
	static_cast<Thread *>(ptr)->run();
	pthread_exit(ptr);
	return 0;
}

void Thread::start()
{
	pthread_create(&this->thread, 0, Thread::dispatch, this);
}

void Thread::join()
{
	pthread_join(this->thread, 0);
}

void Thread::stop()
{
	printf("cancel thread\n");
	this->cancel = 1;
}


