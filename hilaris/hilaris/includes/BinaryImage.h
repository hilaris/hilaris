#ifndef BINARYIMAGE_H
#define BINARYIMAGE_H

#include "oscar.h"
#include "Image.h"

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
		void save(char* path, enum ImageEncoding enc = BMP);
		
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
		 *  @brief Invert this image. Black will become white and vice versa.
		 */
		void invert();
		
		/**
		 *  @brief Get an information wheter black or white is the foreground color.
		 *  @return True if white is foreground, false if it is black.
		 */
		bool getInvertedBackground();
	
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
