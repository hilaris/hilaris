#ifndef _DATA_PROCESSOR_H_
#define _DATA_PROCESSOR_H_

#include "Hilaris.h"

class DataProcessor {
	public:
		virtual ~DataProcessor();
		virtual void* process(Image* image) = 0;
		virtual void setUp() {};
		virtual void tearDown() {};
		virtual void beforeProcess() {};
		virtual void afterProcess() {};
};
#endif 
