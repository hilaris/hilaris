#ifndef _GREYSCALEIMAGEFACTORY_H_
#define _GREYSCALEIMAGEFACTORY_H_

#include "oscar.h"
#include "BinaryImage.h"
#include "GreyscaleImage.h"
#include "RawImage.h"

class GreyscaleImageFactory
{
	public:
		static GreyscaleImage getFastDebayered(RawImage* raw);
		static GreyscaleImage getVectorDebayered(RawImage* raw);
		static GreyscaleImage getHalfsizeDebayered(RawImage* raw);
		static GreyscaleImage getFromBinaryImage(BinaryImage& binary);
		
		static GreyscaleImage create(uint16 width, uint16 height, uint8 color);
};

#endif
