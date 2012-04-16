#ifndef _RAWIMAGE_H_
#define _RAWIMAGE_H_

#include "oscar.h"
#include "Image.h"

/**
 *  @brief A RawImage captured directly from the Camera.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 */
class RawImage : public Image
{	
	public:
	
		/**
		 *  @brief A constructor. Will create a RawImage with the specified width and height.
		 *
		 *  @param width  The width of this Image.
		 *  @param height The height of this Image.
		 */
		RawImage(uint16 width, uint16 height);
		
		EnOscPictureType getType();
		uint8* getDataPtr();
		
	private:
		uint8 data[Image::MAX_WIDTH * Image::MAX_HEIGHT];
};

#endif
