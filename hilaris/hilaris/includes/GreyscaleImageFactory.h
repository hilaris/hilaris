#ifndef _GREYSCALEIMAGEFACTORY_H_
#define _GREYSCALEIMAGEFACTORY_H_

#include "oscar.h"
#include "GreyscaleImage.h"
#include "RawImage.h"
#include "BGRImage.h"
#include "BinaryImage.h"
#include "RGBImage.h"

/**
 *  @brief An Image factory for retrieving a GreyscaleImage
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 */
class GreyscaleImageFactory
{
	public:
	
		/**
		 *  @brief Get a GreyscaleImage out of a RawImage and its data using the fast
		 *   Debayer.
		 *
		 *  @param raw The RawImage from the Camera.
		 *  @return The debayered GreyscaleImage.
		 *
		 *  @warning This function is used internaly in Hilaris and does not have
		 *   to be invoked by a user.
		 */
		static GreyscaleImage getFastDebayered(RawImage* raw);
		
		/**
		 *  @brief Get a GreyscaleImage out of a RawImage and its data using a vector
		 *   based Debayer.
		 *
		 *  @param raw The RawImage from the Camera.
		 *  @return The debayered GreyscaleImage.
		 *
		 *  @warning This function is used internaly in Hilaris and does not have
		 *   to be invoked by a user.
		 */
		static GreyscaleImage getVectorDebayered(RawImage* raw);
		
		/**
		 *  @brief Get a GreyscaleImage out of a RawImage and its data using a
		 *   halfsize Debayer.
		 *
		 *  @param raw The RawImage from the Camera.
		 *  @return The debayered GreyscaleImage.
		 *
		 *  @warning This function is used internaly in Hilaris and does not have
		 *   to be invoked by a user.
		 */
		static GreyscaleImage getHalfsizeDebayered(RawImage* raw);
		
		/**
		 *  @brief Get a GreyscaleImage from a BinaryImage.
		 *
		 *  @param binary An input BinaryImage.
		 *  @return The resulting GreyscaleImage.
		 */
		static GreyscaleImage getFromBinaryImage(BinaryImage& binary);
		
		/**
		 *  @brief Get a GreyscaleImage from a BGRImage.
		 *
		 *  @param bgr An input BGRImage.
		 *  @return The resulting GreyscaleImage.
		 */
		static GreyscaleImage getFromBGRImage(BGRImage& bgr);
		
		/**
		 *  @brief Get a GreyscaleImage from a RGBImage.
		 *
		 *  @param rgb An input RGBImage.
		 *  @return The resulting GreyscaleImage.
		 */
		static GreyscaleImage getFromRGBImage(RGBImage& rgb);
		
		/**
		 *  @brief Create an empty GreyscaleImage and fill it with a specified color.
		 *
		 *  @param width  The width of the resulting image.
		 *  @param height The height of the resulting image.
		 *  @param color  A value from 0 and 255.
		 *
		 *  @return A GreyscaleImage.
		 */
		static GreyscaleImage create(uint16 width, uint16 height, uint8 color);
};

#endif
