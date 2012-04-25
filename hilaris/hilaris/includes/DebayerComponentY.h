#ifndef _DEBAYER_COMPONENT_Y_H_
#define _DEBAYER_COMPONENT_Y_H_

#include <string.h>

#include "oscar.h"
#include "Image.h"
#include "RawImage.h"
#include "ComponentYImage.h"
#include "Debayer.h"

/**
 *  @brief Debayer for the Y-Component of a YUV-Image.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since April 2012
 */
class DebayerComponentY : public Debayer
{
	public:
	
		/**
		 *  @brief Get the image type. The return value is part of the EnOscPictureType enum.
		 *  @return Returns the type of the debayered Image.
		 */
		enum EnOscPictureType getType();
		
		/**
		 *  @brief Get an image pointer.
		 *  @return A pointer to a ComponentYImage.
		 */
		ComponentYImage* getObject(uint16 width, uint16 height);
		
		/**
		 *  @brief This is where the action takes place. Debayer the image according
		 *   to the given image pointer, the raw image pointer and the underlying
		 *   Debayer.
		 *
		 *  @return Success status.
		 */
		bool debayer(RawImage* raw, Image* image);
		
		/**
		 *  @brief Get the size of the resulting Image.
		 *  @return Image size.
		 */
		long unsigned int getSize();
		
		/**
		 *  @brief Create a Debayer instance.
		 */
		DebayerComponentY(){}
		virtual ~DebayerComponentY() {};
};

#endif
