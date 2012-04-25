#ifndef _RAWIMAGE_H_
#define _RAWIMAGE_H_

#include "oscar.h"
#include "Image.h"
#include "BGRImage.h"
#include "RGBImage.h"
#include "GreyscaleImage.h"
#include "ComponentHImage.h"
#include "ComponentSImage.h"
#include "ComponentLImage.h"
#include "ComponentYImage.h"
#include "ComponentUImage.h"
#include "ComponentVImage.h"
#include "YUV422Image.h"

/**
 *  @brief A RawImage captured directly from the Camera.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 */
class RawImage : public Image
{	
	public:
	
		/**
		 *  @brief A constructor. Will create a RawImage with the specified width and height.
		 *
		 *  @param width  The width of this Image.
		 *  @param height The height of this Image.
		 */
		RawImage(uint16 width, uint16 height);
		
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
		 *  @brief Debayer this RawImage to a given GreyscaleImage using a
		 *   fast debayer.
		 *
		 *  @param image A GreyscaleImage pointer.
		 *  @return Success state.
		 */
		bool debayerFast(GreyscaleImage* image);
		
		/**
		 *  @brief Debayer this RawImage to a given GreyscaleImage using a
		 *   vector based debayer.
		 *
		 *  @param image A GreyscaleImage pointer.
		 *  @return Success state.
		 */
		bool debayerVector(GreyscaleImage* image);
		
		/**
		 *  @brief Debayer this RawImage to a given GreyscaleImage using a
		 *   halfsize debayer.
		 *
		 *  @param image A GreyscaleImage pointer.
		 *  @return Success state.
		 */
		bool debayerHalfsize(GreyscaleImage* image);
		
		/**
		 *  @brief Debayer this RawImage to a given BGRImage using a
		 *   fast debayer.
		 *
		 *  @param image A BGRImage pointer.
		 *  @return Success state.
		 */
		bool debayerFast(BGRImage* image);
		
		/**
		 *  @brief Debayer this RawImage to a given BGRImage using a
		 *   bilinear debayer.
		 *
		 *  @param image A BGRImage pointer.
		 *  @return Success state.
		 */
		bool debayerBilinear(BGRImage* image);
		
		/**
		 *  @brief Debayer this RawImage to a given BGRImage using the
		 *   standard debayer.
		 *
		 *  @param image A BGRImage pointer.
		 *  @return Success state.
		 */
		bool debayerStandard(BGRImage* image);
		
		/**
		 *  @brief Debayer this RawImage to a given BGRImage using a
		 *   halfsize debayer.
		 *
		 *  @param image A BGRImage pointer.
		 *  @return Success state.
		 */
		bool debayerHalfsize(BGRImage* image);
		
		/**
		 *  @brief Debayer this RawImage to a given RGBImage using a
		 *   fast debayer.
		 *
		 *  @param image A RGBImage pointer.
		 *  @return Success state.
		 */
		bool debayerFast(RGBImage* image);
		
		/**
		 *  @brief Debayer this RawImage to a given ComponentHImage using a
		 *   fast debayer.
		 *
		 *  @param image A ComponentHImage pointer.
		 *  @return Success state.
		 */
		bool debayerFast(ComponentHImage* image);
		
		/**
		 *  @brief Debayer this RawImage to a given ComponentSImage using a
		 *   fast debayer.
		 *
		 *  @param image A ComponentSImage pointer.
		 *  @return Success state.
		 */
		bool debayerFast(ComponentSImage* image);
		
		/**
		 *  @brief Debayer this RawImage to a given ComponentLImage using a
		 *   fast debayer.
		 *
		 *  @param image A ComponentLImage pointer.
		 *  @return Success state.
		 */
		bool debayerFast(ComponentLImage* image);
		
		/**
		 *  @brief Debayer this RawImage to a given ComponentYImage using a
		 *   fast debayer.
		 *
		 *  @param image A ComponentYImage pointer.
		 *  @return Success state.
		 */
		bool debayerFast(ComponentYImage* image);
		
		/**
		 *  @brief Debayer this RawImage to a given ComponentUImage using a
		 *   fast debayer.
		 *
		 *  @param image A ComponentUImage pointer.
		 *  @return Success state.
		 */
		bool debayerFast(ComponentUImage* image);
		
		/**
		 *  @brief Debayer this RawImage to a given ComponentVImage using a
		 *   fast debayer.
		 *
		 *  @param image A ComponentVImage pointer.
		 *  @return Success state.
		 */
		bool debayerFast(ComponentVImage* image);
		
		/**
		 *  @brief Debayer this RawImage to a given YUV422Image using a
		 *   fast debayer.
		 *
		 *  @param image A YUV422 pointer.
		 *  @return Success state.
		 */
		bool debayerFast(YUV422Image* image);
		
		/**
		 *  @brief Debayer this RawImage to a given BinaryImage using a
		 *   fast debayer.
		 *
		 *  @param image A BinaryImage pointer.
		 *  @param threshold The threshold which should be used.
		 *  @param blackIsForeground Wheter black or white is the foreground color.
		 *
		 *  @return Success state.
		 */
		bool debayerFast(BinaryImage* image, uint8 threshold = 127, bool blackIsForeground = false);
		
		
	private:
		uint8 data[Image::MAX_WIDTH * Image::MAX_HEIGHT];
};

#endif
