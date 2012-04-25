#ifndef _RGBIMAGE_H_
#define _RGBIMAGE_H_

class BinaryImage;
class GreyscaleImage;
class BGRImage;

#include "oscar.h"
#include "Image.h"
#include "GreyscaleImage.h"
#include "BinaryImage.h"
#include "BGRImage.h"

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
		
		/**
		 *  @brief A constructor. Will create a RGBImage with the specified width
		 *    and height using a specified color to fill the Image with.
		 *
		 *  @param width  The width of this Image.
		 *  @param height The height of this Image.
		 *  @param color An uint32 representation of a color.
		 */
		RGBImage(uint16 width, uint16 height, uint32 color);
		
		/**
		 *  @brief A constructor. Will create a RGBImage with the specified width
		 *    and height using a specified color to fill the Image with.
		 *
		 *  @param width  The width of this Image.
		 *  @param height The height of this Image.
		 *  @param red Red component of the color.
		 *  @param green Green component of the color.
		 *  @param blue Blue component of the color.
		 */
		RGBImage(uint16 width, uint16 height, uint8 red, uint16 green, uint16 blue);
		
		EnOscPictureType getType();
		
		/**
		 *  @brief Return a pointer to the underlying image data.
		 *  @return dataptr The data pointer.
		 */
		uint8* getDataPtr();
		
		void save(const char* path, enum ImageEncoding enc = BMP);
		
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
		
		/**
		 *  @brief Convert this RGBImage into a given BinaryImage.
		 *
		 *  @param binary The BinaryImage where all the data should be copied to.
		 *  @param threshold A threshold value to use for the conversion.
		 *  @param darkIsForeground Is black or white the foreground color.
		 *
		 *  @return A pointer to the BinaryImage.
		 */
		BinaryImage* convert(BinaryImage* binary, uint8 threshold = 127, bool darkIsForeground = true);
		
		/**
		 *  @brief Convert this RGBImage into a given GreyscaleImage.
		 *
		 *  @param grey The GreyscaleImage where all the data should be copied to.
		 *  @return A pointer to the GreyscaleImage.
		 */
		GreyscaleImage* convert(GreyscaleImage* grey);
		
		/**
		 *  @brief Convert this RGBImage into a given BGRImage.
		 *
		 *  @param bgr The BGRImage where all the data should be copied to.
		 *  @return A pointer to the BGRImage.
		 */
		BGRImage* convert(BGRImage* bgr);
	
	private:
		uint8 data[Image::MAX_WIDTH * Image::MAX_HEIGHT * 3];
};

#endif
