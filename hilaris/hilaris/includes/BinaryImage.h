#ifndef BINARYIMAGE_H
#define BINARYIMAGE_H

#include <string.h>

class GreyscaleImage;

#include "oscar.h"
#include "Image.h"
#include "GreyscaleImage.h"

/**
 *  @brief A binary image.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 */
class BinaryImage : public Image
{
	public:
	
		/**
		 *  @brief A constructor. Will create a BinaryImage with the specified width and height.
		 *
		 *  @param width  The width of this Image.
		 *  @param height The height of this Image.
		 */
		BinaryImage(uint16 width, uint16 height);
		
		/**
		 *  @brief A constructor. Will create a BinaryImage with the specified width
		 *   and height using a specified color to fill the Image with.
		 *
		 *  @param width  The width of this Image.
		 *  @param height The height of this Image.
		 *  @param color Either 1 or 0.
		 */
		BinaryImage(uint16 width, uint16 height, uint8 color);
		
		/**
		 *  @brief Get the image type.
		 *  @return The image type.
		 */
		EnOscPictureType getType();
		
		/**
		 *  @brief Return a pointer to the underlying image data.
		 *  @return The data pointer.
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
		 *  @brief Get a region struct.
		 *
		 *  @pre Fill the region struct by calling BinaryImage::label.
		 *  @return Information about the inner regions.
		 *
		 *  @see BinaryImage::label, BinaryImage::drawCentroid, BinaryImage::drawBoundingBox
		 */
		OSC_VIS_REGIONS& getRegions();
		
		/**
		 *  @brief Save this image.
		 *
		 *  @param path A path where to save this image.
		 *  @param enc The encoding which should be used. Currently only BMP is
		 *   supported.
		 *
		 *  @warning It is currently not possible to save a BinaryImage directly.
		 *   It will first be converted to a BGRImage which is known to be saveable.
		 */
		void save(const char* path, enum ImageEncoding enc = BMP);
		
		/**
		 *  @brief Erode this image with a given structuring element.
		 *
		 *  @param strel The structuring element.
		 *  @param repetitions How many times it should be eroded.
		 */
		bool erode(struct OSC_VIS_STREL *strel, uint8 repetitions = 1);
		
		/**
		 *  @brief Dilate this image with a given structuring element.
		 *
		 *  @param strel The structuring element.
		 *  @param repetitions How many times it should be dilated.
		 */
		bool dilate(struct OSC_VIS_STREL *strel, uint8 repetitions = 1);
		
		
		/**
		 *  @brief Fill the internal region struct by searching and labeling the
		 *   regions on the current image.
		 *  @return Success status.
		 */
		bool label();
		
		/**
		 *  @brief Draw a centroid marker on every region of this image.
		 *  @pre Fill the region struct by calling BinaryImage::label.
		 *
		 *  @return Success status.
		 *
		 *  @see BinaryImage::label, BinaryImage::drawBoundingBox
		 */
		bool drawCentroid();
		
		/**
		 *  @brief Draw a bounding box for every region of this image.
		 *  @pre Fill the region struct by calling BinaryImage::label.
		 *
		 *  @return Success status.
		 *
		 *  @see BinaryImage::label, BinaryImage::drawBoundingBox
		 */
		bool drawBoundingBox();
		
		/**
		 *  @brief The ()-opeartor. Get and set pixels of this image using this operator.
		 *
		 *  @param x The row, starting at 0.
		 *  @param y The column, starting at 0.
		 *
		 *  @return A reference to the specified pixel.
		 *
		 *  @see BinaryImage::pixel
		 */
		uint8& operator()(const uint16 x, const uint16 y);
		
		/**
		 *  @brief Substract @b in from this image. The pixel values will wrap up.
		 *
		 *  @param in The second BinaryImage.
		 *
		 *  @todo Add correct error handling. Images must be of the same size.
		 *  @todo Image should share the same foregroundColor.
		 *  @todo Add Support for different foregroundColor.
		 *
		 *  @return The resulting BinaryImage.
		 */
		BinaryImage operator-(BinaryImage& in);
		
		/**
		 *  @brief Invert this image. Black will become white and vice versa.
		 */
		void invert();
		
		/**
		 *  @brief Get an information wheter black or white is the foreground color.
		 *  @return True if white is foreground, false if it is black.
		 */
		bool getInvertedBackground();
		
		/**
		 *  @brief Sobel edge detection.
		 *
		 *  This function calculates the sobel operator in x and y direction and combines
		 *  the resulting gradients to a saturated 8-Bit gradient magnitude. Instead of 
		 *  the usual magnitude formula G = sqrt(GxB2 + GyB2) with the resource consuming
		 *  square root function, a simple division by a power of two is used: G = (GxB2 + GyB2) * 2^(-exp).
		 *
		 *  @param exp The exponent for the calculation.
		 *  @return The success status.
		 *
		 *  @note This function leaves a one pixel wide border of the output image untouched.
		 *   Unless these pixels are treated outside this function, they might be in an undefined state.
		 */
		bool sobel(uint8 exp = 10);
		
		/**
		 *  @brief Substract another BinaryImage from this Image.
		 *  @param img A pointer to the resulting BinaryImage.
		 */
		void subtract(BinaryImage* img);
		
		/**
		 *  @brief Convert this BinaryImage into a given GreyscaleImage.
		 *
		 *  @param grey The GreyscaleImage where all the data should be copied to.
		 *  @return A pointer to the GreyscaleImage.
		 *
		 *  @note This is used by Binary::save() because its only possible to
		 *   save images with the type of the GreyscaleImage.
		 */
		GreyscaleImage* convert(GreyscaleImage* grey);
	
	protected:
		
		/**
		 *  @brief Indication if black or white is foreground.
		 *  @see BinaryImage::getInvertedBackground, BinaryImage::invert
		 */
		bool invertedBackground;
		
		/**
		 *  @brief Internal function for setting the background of this image.
		 *  @see BinaryImage::invertedBackground, BinaryImage::getInvertedBackground, BinaryImage::invert
		 */
		void setInvertedBackground(bool set = true);
	
	private:
		uint8 data[Image::MAX_WIDTH * Image::MAX_HEIGHT];
		struct OSC_VIS_REGIONS regions;
		
};

#endif
