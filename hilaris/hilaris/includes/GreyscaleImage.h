#ifndef GREYSCALEIMAGE_H
#define GREYSCALEIMAGE_H

#include "oscar.h"
#include "Image.h"

class GreyscaleImage : public Image
{
	public:
		GreyscaleImage(uint16 width, uint16 height);
		
		EnOscPictureType getType();
		uint8* getDataPtr();
	
	private:
		uint8 data[OSC_CAM_MAX_IMAGE_WIDTH * OSC_CAM_MAX_IMAGE_HEIGHT * 3];
};

#endif
