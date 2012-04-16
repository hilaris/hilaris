#ifndef _RGBImageFACTORY_H_
#define _RGBImageFACTORY_H_

class RGBImage;

#include "oscar.h"
#include "BGRImage.h"
#include "RGBImage.h"
#include "BinaryImage.h"
#include "GreyscaleImage.h"
#include "RawImage.h"

/**
 *  @brief An Image factory for retrieving a RGBImage.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 */
class RGBImageFactory
{
	public:
	
		/**
		 *  @brief Get a RGBImage out of a RawImage and its data using the fast
		 *   debayer.
		 *
		 *  @param raw The RawImage from the Camera.
		 *  @return The debayered RGBImage.
		 *
		 *  @warning This function is used internaly in Hilaris and does not have
		 *   to be invoked by a user.
		 */
		static RGBImage getFastDebayered(RawImage* raw);
		
		/**
		 *  @brief Get a RGBImage from a BGRImage swapping the color components.
		 *
		 *  @param bgr An input BGRImage.
		 *  @return The resulting RGBImage.
		 *
		 *  @see BGRImageFactory::getFromBinaryImage for an example of usage.
		 */
		static RGBImage getFromBGRImage(BGRImage& bgr);
		
		/**
		 *  @brief Get a RGBImage from a GreyscaleImage.
		 *
		 *  @param grey An input GreyscaleImage.
		 *  @return The resulting RGBImage.
		 *
		 *  @see BGRImageFactory::getFromBinaryImage for an example of usage.
		 */
		static RGBImage getFromGreyscaleImage(GreyscaleImage& grey);
		
		/**
		 *  @brief Get a RGBImage from a BinaryImage.
		 *
		 *  @param binary An input BinaryImage.
		 *  @return The resulting RGBImage.
		 *
		 *  @see BGRImageFactory::getFromBinaryImage for an example of usage.
		 */
		static RGBImage getFromBinaryImage(BinaryImage& binary);
		
		/**
		 *  @brief Create an empty BGRImage and fill it with a specified color.
		 *
		 *  @param width  The width of the resulting image.
		 *  @param height The height of the resulting image.
		 *  @param blue   Blue color component of fill color.
		 *  @param green  Green color component of fill color.
		 *  @param red    Red color component of fill color.
		 *
		 *  @return A BGRImage.
		 *
		 *  @include BGRImageFactoryCreate.cpp
		 */
		static RGBImage create(uint16 width, uint16 height, uint8 blue, uint16 green, uint16 red);
};

#endif
