#ifndef _YUV422IMAGE_H_
#define _YUV422IMAGE_H_

#include "oscar.h"
#include "Image.h"

class YUV422Image : public Image
{
	public:
		
		/**
		 *  @brief A constructor. Will create a YUV422Image with the specified width and height.
		 *
		 *  @param width  The width of this Image.
		 *  @param height The height of this Image.
		 */
		YUV422Image(uint16 width, uint16 height);
		
		/**
		 *  @brief Get the image type.
		 *  @return The image type.
		 */
		EnOscPictureType getType();
		
		/**
		 *  @brief Return a pointer to the underlying image data.
		 *  @return dataptr The data pointer.
		 */
		uint8* getDataPtr();
	
	private:
		uint8 data[(Image::MAX_WIDTH / 2) * (Image::MAX_HEIGHT / 2) * 3];
};

#endif
