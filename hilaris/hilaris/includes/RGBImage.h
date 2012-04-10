#ifndef _RGBIMAGE_H_
#define _RGBIMAGE_H_

#include "oscar.h"
#include "Image.h"

enum RGBPixel
{
	RED   = 0,
	GREEN = 1,
	BLUE  = 2
};

class RGBImage : public Image
{
	public:
		RGBImage(uint16 width, uint16 height);
		
		EnOscPictureType getType();
		uint8* getDataPtr();
		
		uint8& pixel(uint16 x, uint16 y, enum RGBPixel compontent);
		uint8& operator()(const uint16 x, const uint16, enum RGBPixel compontent);
	
	private:
		uint8 data[OSC_CAM_MAX_IMAGE_WIDTH * OSC_CAM_MAX_IMAGE_HEIGHT * 3];
};

#endif
