#ifndef _BINARYIMAGEFACTORY_H_
#define _BINARYIMAGEFACTORY_H_

#include "oscar.h"
#include "BinaryImage.h"
#include "GreyscaleImage.h"
#include "RawImage.h"

class BinaryImageFactory
{
	public:
		static BinaryImage getFastDebayered(RawImage* raw, uint8 thresold = 127, bool darkIsForeground = true);
		static BinaryImage getVectorDebayered(RawImage* raw, uint8 thresold = 127, bool darkIsForeground = true);
		static BinaryImage getHalfsizeDebayered(RawImage* raw, uint8 thresold = 127, bool darkIsForeground = true);
		
		static BinaryImage getFromGreyscaleImage(GreyscaleImage& grey, uint8 thresold = 127, bool darkIsForeground = true);
		
		static BinaryImage create(uint16 width, uint16 height, uint8 color);
};

#endif
