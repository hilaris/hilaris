#ifndef _DEBAYER_H_
#define _DEBAYER_H_

#include "oscar.h"
#include "Image.h"

/**
 *  @brief Abstract representation of a Debayer. Must be extended by every single
 *   Debayer implementation.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 */
class Debayer
{
	public:
	
		/**
		 *  @brief Get the image type. The return value is part of the EnOscPictureType enum.
		 *  @return Returns the type of the debayered Image.
		 */
		virtual enum EnOscPictureType getType() = 0;
		
		/**
		 *  @brief Get an image pointer.
		 *  @return A pointer to the extended Image.
		 */
		virtual Image* getObject(uint16 width, uint16 height) = 0;
		
		/**
		 *  @brief This is where the action takes place. Debayer the image according
		 *   to the given image pointer, the raw image pointer and the underlying
		 *   Debayer.
		 *
		 *  @return Success status.
		 */
		 virtual bool debayer(RawImage* raw, Image* image) = 0;
		
		/**
		 *  @brief Get the size of the resulting Image.
		 *  @return Image size.
		 */
		virtual long unsigned int getSize() = 0;
		
		virtual ~Debayer() {};
		
	protected:
	
		/**
		 *  @brief Protected Constructor. This class is more like an interface
		 *   than a real class.
		 */
		Debayer(){}
};

#endif
