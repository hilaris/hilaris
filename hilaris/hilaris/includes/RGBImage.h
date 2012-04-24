#ifndef _RGBIMAGE_H_
#define _RGBIMAGE_H_

#include "oscar.h"
#include "Image.h"
#include "BGRImage.h"
#include "BGRImageFactory.h"

/**
 *  @brief A RGB-encoded colored Image.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 */
class RGBImage : public Image
{
	public:
	
		/**
		 *  @brief The representation of a Pixel, including all components in their
		 *   specific order (RGB -> RED, GREEN, BLUE)
		 */
		enum Pixel
		{
			RED   = 0,
			GREEN = 1,
			BLUE  = 2
		};
		
		
		/**
		 *  @brief A constructor. Will create a RGBImage with the specified width and height.
		 *
		 *  @param width  The width of this Image.
		 *  @param height The height of this Image.
		 */
		RGBImage(uint16 width, uint16 height);
		RGBImage(uint16 width, uint16 height, uint32 color);
		RGBImage(uint16 width, uint16 height, uint8 red, uint16 green, uint16 blue);
		
		EnOscPictureType getType();
		uint8* getDataPtr();
		
		void save(char* path, enum ImageEncoding enc = BMP);
		
		/**
		 *  @brief Get a reference to a single pixel component.
		 *
		 *  @param x The row, starting at 0.
		 *  @param y The column, starting at 0.
		 *  @param component The color component. Can be either BLUE, GREEN or RED.
		 *
		 *  @return A reference to the specified pixel component.
		 */
		uint8& pixel(uint16 x, uint16 y, enum RGBImage::Pixel component);
		
		/**
		 *  @brief The ()-opeartor. Get and set pixels of this image using this operator.
		 *
		 *  @param x The row, starting at 0.
		 *  @param y The column, starting at 0.
		 *  @param component The color component. Can be either BLUE, GREEN or RED.
		 *
		 *  @return A reference to the specified pixel component.
		 *
		 *  @see RGBImage::pixel
		 */
		uint8& operator()(const uint16 x, const uint16, enum RGBImage::Pixel component);
	
	private:
		uint8 data[Image::MAX_WIDTH * Image::MAX_HEIGHT * 3];
};

#endif
