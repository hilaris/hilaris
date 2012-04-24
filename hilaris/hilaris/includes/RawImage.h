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
		
		EnOscPictureType getType();
		uint8* getDataPtr();
		
		bool debayerFast(GreyscaleImage* image);
		bool debayerVector(GreyscaleImage* image);
		bool debayerHalfsize(GreyscaleImage* image);
		
		bool debayerFast(BGRImage* image);
		bool debayerBilinear(BGRImage* image);
		bool debayerStandard(BGRImage* image);
		bool debayerHalfsize(BGRImage* image);
		
		bool debayerFast(RGBImage* image);
		
		bool debayerFast(ComponentHImage* image);
		bool debayerFast(ComponentSImage* image);
		bool debayerFast(ComponentLImage* image);
		bool debayerFast(ComponentYImage* image);
		bool debayerFast(ComponentUImage* image);
		bool debayerFast(ComponentVImage* image);
		bool debayerFast(YUV422Image* image);
		
		
	private:
		uint8 data[Image::MAX_WIDTH * Image::MAX_HEIGHT];
};

#endif
