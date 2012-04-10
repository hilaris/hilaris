#ifndef _BGRIMAGEFACTORY_H_
#define _BGRIMAGEFACTORY_H_

#include "oscar.h"
#include "RGBImage.h"
#include "BGRImage.h"
#include "RawImage.h"

class BGRImageFactory
{
	public:
		static BGRImage getFastDebayered(RawImage* raw);
		static BGRImage getBilinearDebayered(RawImage* raw);
		static BGRImage getDebayered(RawImage* raw);
		static BGRImage getHalfsizeDebayered(RawImage* raw);
		
		static BGRImage getFromRGBImage(RGBImage& rgb);
		
		static BGRImage create(uint16 width, uint16 height, uint8 blue, uint16 green, uint16 red);
};

#endif
