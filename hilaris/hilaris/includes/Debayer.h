#ifndef _DEBAYER_H_
#define _DEBAYER_H_

#include "oscar.h"
#include "Image.h"
#include "RawImage.h"

/**
 *  @brief Abstract representation of a Debayer.
 *
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
		 *
		 *  The enum EnOscPictureType is an enumeration which is used from the oscar framework.
		 *  It contains the following elements: 
		 *  @li OSC_PICTURE_GREYSCALE
		 *  @li OSC_PICTURE_YUV_444
		 *  @li OSC_PICTURE_YUV_422
		 *  @li OSC_PICTURE_YUV_420
		 *  @li OSC_PICTURE_YUV_400
		 *  @li OSC_PICTURE_CHROM_U
		 *  @li OSC_PICTURE_CHROM_V
		 *  @li OSC_PICTURE_HUE
		 *  @li OSC_PICTURE_BGR_24
		 *  @li OSC_PICTURE_RGB_24
		 *  @li OSC_PICTURE_BINARY
		 *
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
