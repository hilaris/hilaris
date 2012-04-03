#ifndef GREYSCALEIMAGE_H
#define GREYSCALEIMAGE_H

#include "oscar.h"
#include "Image.h"
#include "BinaryImage.h"

class GreyscaleImage : public Image
{
	public:
		GreyscaleImage(uint16 width, uint16 height);
		
		EnOscPictureType getType();
		uint8* getDataPtr();
		
		uint8& pixel(uint16 x, uint16 y);
		
		bool filter(struct OSC_VIS_FILTER_KERNEL *kernel);
		
		// operators
		// access via: image(x, y) = pixelvalue;
		uint8& operator()(const uint16 x, const uint16 y);
	
	private:
		uint8 data[OSC_CAM_MAX_IMAGE_WIDTH * OSC_CAM_MAX_IMAGE_HEIGHT];
};

#endif
