#ifndef _IMAGE_BUFFER_H_
#define _IMAGE_BUFFER_H_

#include <string.h>

#include "oscar.h"
#include "Mutex.h"

/**
 *  @brief The ImageBuffer. Will be used while streaming.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 */
class ImageBuffer
{
	public:
		
		/**
		 *  @brief Create an ImageBuffer.
		 *
		 *  @param dataSize The size of the images.
		 *  @param bufferSize The width of this Buffer.
		 */
		ImageBuffer(int dataSize, int bufferSize);
		~ImageBuffer();
		
		/**
		 *  @brief Check wheter the ImageBuffer is empty.
		 *  @return True if Buffer is empty, false otherwise.
		 */
		bool isEmpty();
		
		/**
		 *  @brief Insert a new Image.
		 *  @param img The Image data.
		 */
		void insert(uint8* img);
		
		/**
		 *  @brief Get the current image data according to a RingBuffer rule.
		 *  @return uint8-Array containing Image data.
		 */
		uint8* get();
	
	private:
		Mutex mutex;
		int dataSize;
		int bufferSize;
		int start;
		int count;
		uint8* data;
		uint8* currentImg;
};

#endif
