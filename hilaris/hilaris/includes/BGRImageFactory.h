#ifndef _BGRIMAGEFACTORY_H_
#define _BGRIMAGEFACTORY_H_

class RGBImage;

#include "oscar.h"
#include "BGRImage.h"
#include "RGBImage.h"
#include "BinaryImage.h"
#include "GreyscaleImage.h"
#include "RawImage.h"

/**
 *  @brief An Image factory for retrieving a BGRImages
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
		static BGRImage getFastDebayered(RawImage* raw);
		static BGRImage getBilinearDebayered(RawImage* raw);
		static BGRImage getDebayered(RawImage* raw);
		static BGRImage getHalfsizeDebayered(RawImage* raw);
		
		static BGRImage getFromRGBImage(RGBImage& rgb);
		static BGRImage getFromGreyscaleImage(GreyscaleImage& grey);
		static BGRImage getFromBinaryImage(BinaryImage& binary);
		
		/**
		 *  @brief Create an empty BGRImage and fill it with a specified color.
		 *
		 *  @param width  The width of the resulting image.
		 *  @param height The height of the resulting image.
		 *  @param blue   Blue color Component of filling color.
		 *  @param green  Green color Component of filling color.
		 *  @param red    Red color Component of filling color.
		 *
		 *  @return A BGRImage.
		 *
		 *  @include BGRImageFactoryCreate.cpp
		 */
		static BGRImage create(uint16 width, uint16 height, uint8 blue, uint16 green, uint16 red);
};

#endif
