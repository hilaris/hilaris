#ifndef _BGRIMAGEFACTORY_H_
#define _BGRIMAGEFACTORY_H_

#include "oscar.h"
#include "BGRImage.h"
#include "RawImage.h"

class BGRImageFactory
{
	public:
		static BGRImage getFastDebayered(RawImage* raw);
		static BGRImage getBilinearDebayered(RawImage* raw);
		static BGRImage getDebayered(RawImage* raw);
		static BGRImage getHalfsizeDebayered(RawImage* raw);
};

#endif
