#ifndef _BINARYIMAGEFACTORY_H_
#define _BINARYIMAGEFACTORY_H_

#include "oscar.h"
#include "BinaryImage.h"
#include "RawImage.h"
#include "GreyscaleImage.h"
#include "BGRImage.h"
#include "RGBImage.h"
#include "GreyscaleImageFactory.h"

class BinaryImageFactory
{
	public:
		// @todo - darkisforeground?
		static BinaryImage getFastDebayered(RawImage* raw, uint8 thresold = 127, bool darkIsForeground = true);
		static BinaryImage getVectorDebayered(RawImage* raw, uint8 thresold = 127, bool darkIsForeground = true);
		static BinaryImage getHalfsizeDebayered(RawImage* raw, uint8 thresold = 127, bool darkIsForeground = true);
		
		static BinaryImage getFromGreyscaleImage(GreyscaleImage& grey, uint8 thresold = 127, bool darkIsForeground = true);
		static BinaryImage getFromBGRImage(BGRImage& bgr, uint8 thresold = 127, bool darkIsForeground = true);
		static BinaryImage getFromRGBImage(RGBImage& rgb, uint8 thresold = 127, bool darkIsForeground = true);
		
		static BinaryImage create(uint16 width, uint16 height, uint8 color);
};

#endif
