#ifndef _BINARYIMAGEFACTORY_H_
#define _BINARYIMAGEFACTORY_H_

#include "oscar.h"
#include "BinaryImage.h"
#include "GreyscaleImage.h"
#include "RawImage.h"

class BinaryImageFactory
{
	public:
		static BinaryImage getFastDebayered(RawImage* raw, uint8 thresold, bool darkIsForeground);
		static BinaryImage getVectorDebayered(RawImage* raw, uint8 thresold, bool darkIsForeground);
		static BinaryImage getHalfsizeDebayered(RawImage* raw, uint8 thresold, bool darkIsForeground);
		
		static BinaryImage getFromGreyscaleImage(GreyscaleImage& grey, uint8 thresold = 128, bool darkIsForeground = true);
};

#endif
