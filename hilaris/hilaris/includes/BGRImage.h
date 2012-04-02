#ifndef BGRIMAGE_H
#define BGRIMAGE_H

#include "oscar.h"
#include "Image.h"

class BGRImage : public Image
{
	public:
		BGRImage(uint16 width, uint16 height);
		
		EnOscPictureType getType();
	
	private:
		uint8 data[OSC_CAM_MAX_IMAGE_WIDTH * OSC_CAM_MAX_IMAGE_HEIGHT * 3];
};

#endif
