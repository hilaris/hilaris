#ifndef GREYSCALEIMAGE_H
#define GREYSCALEIMAGE_H

class Histogram;

#include "oscar.h"
#include "Image.h"
#include "Histogram.h"

/**
 *  @brief A greyscale image.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 */
class GreyscaleImage : public Image
{
	public:
	
		/**
		 *  @brief A constructor. Will create a GreyscaleImage with the specified width and height.
		 *
		 *  @param width  The width of this Image.
		 *  @param height The height of this Image.
		 */
		GreyscaleImage(uint16 width, uint16 height);
		GreyscaleImage(uint16 width, uint16 height, uint8 color);
		
		~GreyscaleImage();
		
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
		 *  @brief Get a reference to a single pixel.
		 *
		 *  @param x The row, starting at 0.
		 *  @param y The column, starting at 0.
		 *
		 *  @return A reference to the specified pixel.
		 */
		uint8& pixel(uint16 x, uint16 y);
		
		/**
		 *  @brief Execute a 2D filter based on a given filter kernel.
		 *
		 *  @param kernel The filter kernel.
		 *  @return Success status.
		 */
		bool filter(struct OSC_VIS_FILTER_KERNEL *kernel);
		
		bool sobel(uint8 exp = 10);
		
		/**
		 *  @brief The ()-opeartor. Get and set pixels of this image using this operator.
		 *
		 *  @param x The row, starting at 0.
		 *  @param y The column, starting at 0.
		 *
		 *  @return A reference to the specified pixel.
		 *
		 *  @see GreyscaleImage::pixel
		 */
		uint8& operator()(const uint16 x, const uint16 y);
		
		Histogram* histogram();
	
	private:
		uint8 data[Image::MAX_WIDTH * Image::MAX_HEIGHT];
		Histogram* hist;
};

#endif
