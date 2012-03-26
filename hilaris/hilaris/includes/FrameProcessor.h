#ifndef _FRAME_PROCESSOR_H_
#define _FRAME_PROCESSOR_H_

class FrameProcessor {
	public:
		virtual Image* process(Image* image) = 0;
		virtual void setUp() {};
		virtual void tearDown() {};
		virtual void beforeProcess() {};
		virtual void afterProcess() {};
};

#endif 
