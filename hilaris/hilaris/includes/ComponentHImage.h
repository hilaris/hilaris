#ifndef _COMPONENT_H_IMAGE_
#define _COMPONENT_H_IMAGE_

#include "oscar.h"
#include "Image.h"

class ComponentHImage : public Image
{
	public:
	
		ComponentHImage(uint16 width, uint16 height);
		EnOscPictureType getType();
		uint8* getDataPtr();
		
	private:
		uint8 data[(Image::MAX_WIDTH / 2) * (Image::MAX_HEIGHT / 2)];
};


#endif
