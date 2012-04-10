#ifndef _BGRIMAGE_H_
#define _BGRIMAGE_H_

#include "oscar.h"
#include "Image.h"

class BGRImage : public Image
{
	public:
	
		enum Pixel
		{
			BLUE  = 0,
			GREEN = 1,
			RED   = 2
		};

		BGRImage(uint16 width, uint16 height);
		
		EnOscPictureType getType();
		uint8* getDataPtr();
		
		uint8& pixel(uint16 x, uint16 y, enum BGRImage::Pixel compontent);
		uint8& operator()(const uint16 x, const uint16, enum BGRImage::Pixel compontent);
	
	private:
		uint8 data[OSC_CAM_MAX_IMAGE_WIDTH * OSC_CAM_MAX_IMAGE_HEIGHT * 3];
};

#endif
