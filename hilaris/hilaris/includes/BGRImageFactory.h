/** 
 *  Hilaris — Using the LeanXcam has never been easier!
 *  Copyright (C) 2012 Jim Schmid & Michael Kreis
 *  
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

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
		static BGRImage create(uint16 width, uint16 height, uint8 blue, uint16 green, uint16 red);
};

#endif
