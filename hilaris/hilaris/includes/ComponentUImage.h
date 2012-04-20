#ifndef _COMPONENT_U_IMAGE_
#define _COMPONENT_U_IMAGE_

#include "oscar.h"
#include "Image.h"

class ComponentUImage : public Image
{
	public:
	
		ComponentUImage(uint16 width, uint16 height);
		EnOscPictureType getType();
		uint8* getDataPtr();
		
	private:
		uint8 data[(Image::MAX_WIDTH / 2) * (Image::MAX_HEIGHT / 2)];
};

#endif
