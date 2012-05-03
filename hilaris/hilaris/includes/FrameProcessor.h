#ifndef _FRAME_PROCESSOR_H_
#define _FRAME_PROCESSOR_H_

#include "Image.h"

/**
 *  @brief Base class for all FrameProcessors.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 */
class FrameProcessor {
	public:
		/**
		 *  @brief This is where the action of processing takes place. Alter the
		 *   image and return it afterwards.
		 *  @return The input image pointer.
		 */
		virtual Image* process(Image* image) = 0;
		
		virtual ~FrameProcessor() {};
};

#endif 
