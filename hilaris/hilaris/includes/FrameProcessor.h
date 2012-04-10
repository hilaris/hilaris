#ifndef _FRAME_PROCESSOR_H_
#define _FRAME_PROCESSOR_H_

#include "Image.h"

class FrameProcessor {
	public:
		virtual Image* process(Image* image) = 0;
		virtual void setUp() {};
		virtual void tearDown() {};
		virtual void beforeProcess() {};
		virtual void afterProcess() {};
		
		virtual ~FrameProcessor() {};
};

#endif 
