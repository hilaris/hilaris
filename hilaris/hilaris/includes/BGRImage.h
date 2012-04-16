#ifndef _BGRIMAGE_H_
#define _BGRIMAGE_H_

#include "oscar.h"
#include "Image.h"
/**
 *  @brief A BGR-encoded colored Image.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
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
	
	private:
		uint8 data[OSC_CAM_MAX_IMAGE_WIDTH * OSC_CAM_MAX_IMAGE_HEIGHT * 3];
};

#endif
