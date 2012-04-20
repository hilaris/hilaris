#ifndef _DEBAYER_COMPONENT_U_H_
#define _DEBAYER_COMPONENT_U_H_

#include <string.h>

#include "oscar.h"
#include "Image.h"
#include "RawImage.h"
#include "ComponentUImage.h"
#include "ComponentUImageFactory.h"
#include "Debayer.h"

class DebayerComponentU : public Debayer
{
	public:
	
		/**
		 *  @brief Get the image type. The return value is part of the EnOscPictureType enum.
		 *  @return Returns the type of the debayered Image.
		 */
		enum EnOscPictureType getType();
		
		/**
		 *  @brief Get an image pointer.
		 *  @return A pointer to a ComponentUImage.
		 */
		ComponentUImage* getObject(uint16 width, uint16 height);
		
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
		
		DebayerComponentU(){}
		virtual ~DebayerComponentU() {};
};

#endif
