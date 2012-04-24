#ifndef _BGRIMAGEFACTORY_H_
#define _BGRIMAGEFACTORY_H_

class RGBImage;
class RawImage;

#include "oscar.h"
#include "BGRImage.h"
#include "RGBImage.h"
#include "BinaryImage.h"
#include "GreyscaleImage.h"
#include "RawImage.h"

/**
 *  @brief An Image factory for retrieving a BGRImage
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 */
class BGRImageFactory
{
	public:
	
		/**
		 *  @brief Get a BGRImage out of a RawImage and its data using the fast
		 *   debayer.
		 *
		 *  @param raw The RawImage from the Camera.
		 *  @return The debayered BGRImage.
		 *
		 *  @warning This function is used internaly in Hilaris and does not have
		 *   to be invoked by a user.
		 */
		static BGRImage getFastDebayered(RawImage* raw);
		
		/**
		 *  @brief Get a BGRImage out of a RawImage and its data using a bilinear
		 *   debayer.
		 *
		 *  @param raw The RawImage from the Camera.
		 *  @return The debayered BGRImage.
		 *
		 *  @warning This function is used internaly in Hilaris and does not have
		 *   to be invoked by a user.
		 */
		static BGRImage getBilinearDebayered(RawImage* raw);
		
		/**
		 *  @brief Get a BGRImage out of a RawImage and its data using the standard
		 *   debayer.
		 *
		 *  @param raw The RawImage from the Camera.
		 *  @return The debayered BGRImage.
		 *
		 *  @warning This function is used internaly in Hilaris and does not have
		 *   to be invoked by a user.
		 */
		static BGRImage getDebayered(RawImage* raw);
		
		/**
		 *  @brief Get a BGRImage out of a RawImage and its data using a halfsize
		 *   debayer.
		 *
		 *  @param raw The RawImage from the Camera.
		 *  @return The debayered BGRImage.
		 *
		 *  @warning This function is used internaly in Hilaris and does not have
		 *   to be invoked by a user.
		 */
		static BGRImage getHalfsizeDebayered(RawImage* raw);
		
		
		/**
		 *  @brief Get a BGRImage from a RGBImage swapping the color components.
		 *
		 *  @param rgb An input RGBImage.
		 *  @return The resulting BGRImage.
		 *
		 *  @see BGRImageFactory::getFromBinaryImage for an example of usage.
		 */
		static BGRImage getFromRGBImage(RGBImage& rgb);
		
		/**
		 *  @brief Get a BGRImage from a GreyscaleImage.
		 *
		 *  @param grey An input GreyscaleImage.
		 *  @return The resulting BGRImage.
		 *
		 *  @see BGRImageFactory::getFromBinaryImage for an example of usage.
		 */
		static BGRImage getFromGreyscaleImage(GreyscaleImage& grey);
		
		/**
		 *  @brief Get a BGRImage from a BinaryImage.
		 *
		 *  @param binary An input BinaryImage.
		 *  @return The resulting BGRImage.
		 *
		 *  @include BGRImageFactoryFromBinaryImage.cpp
		 */
		static BGRImage getFromBinaryImage(BinaryImage& binary);
		
		/**
		 *  @brief Create an empty RGBImage and fill it with a specified color.
		 *
		 *  @param width  The width of the resulting image.
		 *  @param height The height of the resulting image.
		 *  @param red    Red color component of fill color.
		 *  @param green  Green color component of fill color.
		 *  @param blue   Blue color component of fill color.
		 *
		 *  @return A RGBImage.
		 *
		 *  @include BGRImageFactoryCreate.cpp
		 */
		static BGRImage create(uint16 width, uint16 height, uint8 red, uint16 green, uint16 blue);
};

#endif
