#ifndef _RGBIMAGE_H_
#define _RGBIMAGE_H_

#include "oscar.h"
#include "Image.h"
#include "BGRImage.h"
#include "BGRImageFactory.h"

class RGBImage : public Image
{
	public:
	
		enum Pixel
		{
			RED   = 0,
			GREEN = 1,
			BLUE  = 2
		};
		
		RGBImage(uint16 width, uint16 height);
		
		EnOscPictureType getType();
		uint8* getDataPtr();
		
		// overriden save function
		void save(char* path, enum ImageEncoding enc = BMP);
		
		uint8& pixel(uint16 x, uint16 y, enum RGBImage::Pixel compontent);
		uint8& operator()(const uint16 x, const uint16, enum RGBImage::Pixel compontent);
	
	private:
		uint8 data[OSC_CAM_MAX_IMAGE_WIDTH * OSC_CAM_MAX_IMAGE_HEIGHT * 3];
};

#endif
