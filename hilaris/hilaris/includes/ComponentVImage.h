#ifndef _COMPONENT_V_IMAGE_
#define _COMPONENT_V_IMAGE_

#include "oscar.h"
#include "Image.h"

/**
 *  @brief The V-Component of a YUV-Image.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 */
class ComponentVImage : public Image
{
	public:

		/**
		 *  @brief Create an empty ComponentVImage.
		 *
		 *  @param width The width of the Image.
		 *  @param height The height of the Image.
		 */
		ComponentVImage(uint16 width, uint16 height);
		
		/**
		 *  @brief Get the type of this Image.
		 *  @return The image type.
		 */
		EnOscPictureType getType();
		
		/**
		 *  @brief Retrieve the Pointer to the data segment of this Image.
		 *  @return A data pointer.
		 */
		uint8* getDataPtr();
		
	private:
		uint8 data[(Image::MAX_WIDTH / 2) * (Image::MAX_HEIGHT / 2)];
};

#endif
