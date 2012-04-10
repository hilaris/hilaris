#ifndef _RGBImageFACTORY_H_
#define _RGBImageFACTORY_H_

class RGBImage;

#include "oscar.h"
#include "BGRImage.h"
#include "RGBImage.h"
#include "BinaryImage.h"
#include "GreyscaleImage.h"
#include "RawImage.h"

class RGBImageFactory
{
	public:
		static RGBImage getFastDebayered(RawImage* raw);
		
		static RGBImage getFromBGRImage(BGRImage& rgb);
		static RGBImage getFromGreyscaleImage(GreyscaleImage& grey);
		static RGBImage getFromBinaryImage(BinaryImage& binary);
		
		static RGBImage create(uint16 width, uint16 height, uint8 blue, uint16 green, uint16 red);
};

#endif
