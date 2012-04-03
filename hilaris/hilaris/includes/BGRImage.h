#ifndef BGRIMAGE_H
#define BGRIMAGE_H

#include "oscar.h"
#include "Image.h"

struct BGRPixel
{
	uint8 blue;
	uint8 green;
	uint8 red;
};

class BGRImage : public Image
{
	public:
		BGRImage(uint16 width, uint16 height);
		
		EnOscPictureType getType();
		uint8* getDataPtr();
		
		void pixel(uint16 x, uint16 y, struct BGRPixel& pixel);
		uint8& component(uint16 x, uint16 y);
		
		// operators
		// access via: image(x, y) = pixelvalue;
		BGRPixel& operator()(const uint16 x, const uint16 y, struct BGRPixel& pixel);
		uint8&    operator()(const uint16 x, const uint16);
	
	private:
		uint8 data[OSC_CAM_MAX_IMAGE_WIDTH * OSC_CAM_MAX_IMAGE_HEIGHT * 3];
};

#endif
