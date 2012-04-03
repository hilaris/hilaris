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
	
	private:
		uint8 data[OSC_CAM_MAX_IMAGE_WIDTH * OSC_CAM_MAX_IMAGE_HEIGHT];
};

#endif
