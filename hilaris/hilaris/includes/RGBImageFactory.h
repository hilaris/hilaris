#ifndef _RGBImageFACTORY_H_
#define _RGBImageFACTORY_H_

#include "oscar.h"
#include "RGBImage.h"
#include "RawImage.h"

class RGBImageFactory
{
	public:
		static RGBImage getFastDebayered(RawImage* raw);
		
		static RGBImage create(uint16 width, uint16 height, uint8 blue, uint16 green, uint16 red);
};

#endif
