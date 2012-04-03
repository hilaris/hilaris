#ifndef BINARYIMAGE_H
#define BINARYIMAGE_H

#include "oscar.h"
#include "Image.h"

class BinaryImage : public Image
{
	public:
		BinaryImage(uint16 width, uint16 height);
		
		EnOscPictureType getType();
		uint8* getDataPtr();
		
		uint8& pixel(uint16 x, uint16 y);
		
		// overriden save function
		void save(char* path, enum ImageEncoding enc = BMP);
		
		// operators
		// access via: image(x, y) = pixelvalue;
		uint8& operator()(const uint16 x, const uint16 y);
	
	private:
		uint8 data[OSC_CAM_MAX_IMAGE_WIDTH * OSC_CAM_MAX_IMAGE_HEIGHT];
};

#endif
