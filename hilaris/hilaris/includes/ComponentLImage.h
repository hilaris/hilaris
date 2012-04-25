#ifndef _COMPONENT_L_IMAGE_
#define _COMPONENT_L_IMAGE_

#include "oscar.h"
#include "Image.h"

/**
 *  @brief The L-Component of a HSL-Image.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 */
class ComponentLImage : public Image
{
	public:
	
		/**
		 *  @brief Create an empty ComponentLImage.
		 *
		 *  @param width The width of the Image.
		 *  @param height The height of the Image.
		 */
		ComponentLImage(uint16 width, uint16 height);
		
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
