#ifndef _RAWIMAGE_H_
#define _RAWIMAGE_H_

#include "oscar.h"
#include "Image.h"

class RawImage : public Image
{	
	public:
		RawImage(uint16 width, uint16 height);
		
		EnOscPictureType getType();
		
		uint8 data[OSC_CAM_MAX_IMAGE_WIDTH * OSC_CAM_MAX_IMAGE_HEIGHT];
	private:
};

#endif
