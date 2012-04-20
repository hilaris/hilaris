#ifndef _BINARYIMAGEFACTORY_H_
#define _BINARYIMAGEFACTORY_H_

#include "oscar.h"
#include "BinaryImage.h"
#include "RawImage.h"
#include "GreyscaleImage.h"
#include "BGRImage.h"
#include "RGBImage.h"
#include "GreyscaleImageFactory.h"

/**
 *  @brief An Image factory for retrieving a BinaryImage
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 */
class BinaryImageFactory
{
	public:
		
		static BinaryImage getDirectDebayered(RawImage* raw, uint8 threshold = 127, bool darkIsForeground = true);
		
		/**
		 *  @brief Get a BinaryImage out of a RawImage and its data using the greyscale fast
		 *   Debayer.
		 *
		 *  @param raw The RawImage from the Camera.
		 *  @param threshold (@b optional) A threshold value for generating the BinaryImage out
		 *   of the input Image.
		 *  @param darkIsForeground (@b optional) Indicates wheter black or white should be
		 *   the foreground of the Image.
		 *
		 *  @return The debayered BinaryImage.
		 *
		 *  @see GreyscaleImageFactory::getFastDebayered for details.
		 *
		 *  @warning This function is used internaly in Hilaris and does not have
		 *   to be invoked by a user.
		 */
		static BinaryImage getFastDebayered(RawImage* raw, uint8 threshold = 127, bool darkIsForeground = true);
		
		/**
		 *  @brief Get a BinaryImage out of a RawImage and its data using the greyscale vector based
		 *   Debayer.
		 *
		 *  @param raw The RawImage from the Camera.
		 *  @param threshold (@b optional) A threshold value for generating the BinaryImage out
		 *   of the input Image.
		 *  @param darkIsForeground (@b optional) Indicates wheter black or white should be
		 *   the foreground of the Image.
		 *
		 *  @return The debayered BinaryImage.
		 *
		 *  @see GreyscaleImageFactory::getVectorDebayered for details.
		 *
		 *  @warning This function is used internaly in Hilaris and does not have
		 *   to be invoked by a user.
		 */
		static BinaryImage getVectorDebayered(RawImage* raw, uint8 threshold = 127, bool darkIsForeground = true);
		
		/**
		 *  @brief Get a BinaryImage out of a RawImage and its data using the greyscale halfsize
		 *   Debayer.
		 *
		 *  @param raw The RawImage from the Camera.
		 *  @param threshold (@b optional) A threshold value for generating the BinaryImage out
		 *   of the input Image.
		 *  @param darkIsForeground (@b optional) Indicates wheter black or white should be
		 *   the foreground of the Image.
		 *
		 *  @return The debayered BinaryImage.
		 *
		 *  @see GreyscaleImageFactory::getHalfsizeDebayered for details.
		 *
		 *  @warning This function is used internaly in Hilaris and does not have
		 *   to be invoked by a user.
		 */
		static BinaryImage getHalfsizeDebayered(RawImage* raw, uint8 threshold = 127, bool darkIsForeground = true);
		
		
		/**
		 *  @brief Get a BinaryImage from a GreyscaleImage.
		 *
		 *  @param grey An input GreyscaleImage.
		 *  @param threshold (@b optional) A threshold value for generating the BinaryImage out
		 *   of the input Image.
		 *  @param darkIsForeground (@b optional) Indicates wheter black or white should be
		 *   the foreground of the Image.
		 *
		 *  @return The resulting BinaryImage.
		 */
		static BinaryImage getFromGreyscaleImage(GreyscaleImage& grey, uint8 threshold = 127, bool darkIsForeground = true);
		
		/**
		 *  @brief Get a BinaryImage from a BGRImage.
		 *
		 *  @param bgr An input BGRImage.
		 *  @param threshold (@b optional) A threshold value for generating the BinaryImage out
		 *   of the input Image.
		 *  @param darkIsForeground (@b optional) Indicates wheter black or white should be
		 *   the foreground of the Image.
		 *
		 *  @return The resulting BinaryImage.
		 */
		static BinaryImage getFromBGRImage(BGRImage& bgr, uint8 threshold = 127, bool darkIsForeground = true);
		
		/**
		 *  @brief Get a BinaryImage from a RGBImage.
		 *
		 *  @param rgb An input RGBImage.
		 *  @param threshold (@b optional) A threshold value for generating the BinaryImage out
		 *   of the input Image.
		 *  @param darkIsForeground (@b optional) Indicates wheter black or white should be
		 *   the foreground of the Image.
		 *
		 *  @return The resulting BinaryImage.
		 */
		static BinaryImage getFromRGBImage(RGBImage& rgb, uint8 threshold = 127, bool darkIsForeground = true);
		
		/**
		 *  @brief Create an empty BinaryImage and fill it with a specified color.
		 *
		 *  @param width  The width of the resulting image.
		 *  @param height The height of the resulting image.
		 *  @param color  Either 1 or 0
		 *
		 *  @return A BinaryImage.
		 *
		 *  @todo add correct error handling, like whatif width is not dividable by 4 etc.
		 */
		static BinaryImage create(uint16 width, uint16 height, uint8 color);
};

#endif
