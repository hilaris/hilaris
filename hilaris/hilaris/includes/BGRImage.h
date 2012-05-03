#ifndef _BGRIMAGE_H_
#define _BGRIMAGE_H_

class RGBImage;

#include "oscar.h"
#include "Image.h"
#include "BinaryImage.h"
#include "GreyscaleImage.h"
#include "RGBImage.h"
#include "BGRImage.h"

/**
 *  @brief A BGR-encoded colored Image.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 *
 *  @image html bgr.bmp A sample BGRImage.
 */
class BGRImage : public Image
{
	public:
	
		/**
		 *  @brief The representation of a Pixel, including all components in their
		 *   specific order (BGR -> BLUE, GREEN, RED)
		 */
		enum Pixel
		{
			BLUE  = 0,
			GREEN = 1,
			RED   = 2
		};
		
		/**
		 *  @brief A constructor. Will create a BGRImage with the specified width and height.
		 *
		 *  @param width  The width of this Image.
		 *  @param height The height of this Image.
		 */
		BGRImage(uint16 width, uint16 height);
		
		/**
		 *  @brief A constructor. Will create a BGRImage with the specified width
		 *    and height using a specified color to fill the Image with.
		 *
		 *  @param width  The width of this Image.
		 *  @param height The height of this Image.
		 *  @param color An uint32 representation of a color.
		 */
		BGRImage(uint16 width, uint16 height, uint32 color);
		
		/**
		 *  @brief A constructor. Will create a BGRImage with the specified width
		 *    and height using a specified color to fill the Image with.
		 *
		 *  @param width  The width of this Image.
		 *  @param height The height of this Image.
		 *  @param blue Blue component of the color.
		 *  @param green Green component of the color.
		 *  @param red Red component of the color.
		 */
		BGRImage(uint16 width, uint16 height, uint8 blue, uint8 green, uint8 red);
		
		/**
		 *  @brief Get the image type.
		 *  @return The image type.
		 */
		EnOscPictureType getType();
		
		/**
		 *  @brief Return a pointer to the underlying image data.
		 *  @return dataptr The data pointer.
		 */
		uint8* getDataPtr();
		
		/**
		 *  @brief Get a reference to a single pixel component.
		 *
		 *  @param x The row, starting at 0.
		 *  @param y The column, starting at 0.
		 *  @param component The color component. Can be either BLUE, GREEN or RED.
		 *
		 *  @return A reference to the specified pixel component.
		 */
		uint8& pixel(uint16 x, uint16 y, enum BGRImage::Pixel component);
		
		/**
		 *  @brief The ()-opeartor. Get and set pixels of this image using this operator.
		 *
		 *  @param x The row, starting at 0.
		 *  @param y The column, starting at 0.
		 *  @param component The color component. Can be either BLUE, GREEN or RED.
		 *
		 *  @return A reference to the specified pixel component.
		 *
		 *  @see BGRImage::pixel
		 */
		uint8& operator()(const uint16 x, const uint16, enum BGRImage::Pixel component);
		
		/**
		 *  @brief Convert this BGRImage into a given BinaryImage.
		 *
		 *  @param binary The BinaryImage where all the data should be copied to.
		 *  @param threshold A threshold value to use for the conversion.
		 *  @param darkIsForeground Is black or white the foreground color.
		 *
		 *  @return A pointer to the BinaryImage.
		 */
		BinaryImage* convert(BinaryImage* binary, uint8 threshold = 127, bool darkIsForeground = true);
		
		/**
		 *  @brief Convert this BGRImage into a given GreyscaleImage.
		 *
		 *  @param grey The GreyscaleImage where all the data should be copied to.
		 *  @return A pointer to the GreyscaleImage.
		 */
		GreyscaleImage* convert(GreyscaleImage* grey);
		
		/**
		 *  @brief Convert this BGRImage into a given RGBImage.
		 *
		 *  @param rgb The RGBImage where all the data should be copied to.
		 *  @return A pointer to the RGBImage.
		 */
		RGBImage* convert(RGBImage* rgb);
	
	private:
		uint8 data[Image::MAX_WIDTH * Image::MAX_HEIGHT * 3];
};

#endif
