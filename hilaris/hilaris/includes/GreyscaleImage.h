#ifndef GREYSCALEIMAGE_H
#define GREYSCALEIMAGE_H

class Histogram;

#include "oscar.h"
#include "Image.h"
#include "BGRImage.h"
#include "RGBImage.h"
#include "Histogram.h"

/**
 *  @brief A greyscale image.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 *
 *  @image html greyscale.bmp A sample GreyscaleImage.
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
		
		/**
		 *  @brief A constructor. Will create a GreyscaleImage with the specified
		 *   width and height using a specified color to fill the Image with.
		 *
		 *  @param width  The width of this Image.
		 *  @param height The height of this Image.
		 *  @param color An uint8 representation of a color.
		 */
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
		
		/**
		 *  @brief Sobel edge detection.
		 *
		 *  @param exp The exponent used in the calculations.
		 *  @return Success status.
		 */
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
		
		
		/**
		 *  @brief Retrieve a Histogram pointer.
		 *
		 *  @return A pointer to the Histogram of this GreyscaleImage.
		 *
		 *  @note  This will call Histogram::init()
		 *
		 *  @image html greyscale.bmp Before.
		 *  @image html histogram.bmp After calling greyscaleImage->histogram()->equalize()
		 */
		Histogram* histogram();
		
		/**
		 *  @brief Convert this GreyscaleImage into a given BGRImage.
		 *
		 *  @param bgr The BGRImage where all the data should be copied to.
		 *  @return A pointer to the BGRImage.
		 */
		BGRImage* convert(BGRImage* bgr);
		
		/**
		 *  @brief Convert this GreyscaleImage into a given RGBImage.
		 *
		 *  @param rgb The RGBImage where all the data should be copied to.
		 *  @return A pointer to the RGBImage.
		 */
		RGBImage* convert(RGBImage* rgb);
		
		/**
		 *  @brief Convert this GreyscaleImage into a given BinaryImage.
		 *
		 *  @param binary The BinaryImage where all the data should be copied to.
		 *  @param threshold A threshold value to use for the conversion.
		 *  @param darkIsForeground Is black or white the foreground color.
		 *
		 *  @return A pointer to the BinaryImage.
		 */
		BinaryImage* convert(BinaryImage* binary, uint8 threshold = 127, bool darkIsForeground = true);
	
	private:
		uint8 data[Image::MAX_WIDTH * Image::MAX_HEIGHT];
		Histogram* hist;
};

#endif
