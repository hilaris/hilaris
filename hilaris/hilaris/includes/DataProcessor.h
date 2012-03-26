#ifndef _DATA_PROCESSOR_H_
#define _DATA_PROCESSOR_H_

class DataProcessor {
	public:
		virtual void* process(Image* image) = 0;
		virtual void setUp() {};
		virtual void tearDown() {};
		virtual void beforeProcess() {};
		virtual void afterProcess() {};
};
#endif 
