#ifndef _RAWIMAGE_H_
#define _RAWIMAGE_H_

#include "oscar.h"
#include "Image.h"

class RawImage : public Image
{	
	public:
		RawImage(uint16 width, uint16 height);
		
		EnOscPictureType getType();
};

#endif
