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
		
		/**
		 *  @brief A callback function which will be executed after the constructor
		 *   has been called.
		 */
		virtual void setUp() {};
		
		/**
		 *  @brief A callback function which will be executed before the deconstructor
		 *   will be called.
		 */
		virtual void tearDown() {};
		
		/**
		 *  @brief A callback function which will be executed before the image
		 *   will be processed.
		 */
		virtual void beforeProcess() {};
		
		/**
		 *  @brief A callback function which will be executed after the image
		 *   has been processed.
		 */
		virtual void afterProcess() {};
		
		virtual ~FrameProcessor() {};
};

#endif 
