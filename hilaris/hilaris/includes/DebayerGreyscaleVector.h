#ifndef _DEBAYERGREYSCALEVECTOR_H_
#define _DEBAYERGREYSCALEVECTOR_H_

#include "Debayer.h"
#include "GreyscaleImage.h"
#include "GreyscaleImageFactory.h"

#include <string.h>

class DebayerGreyscaleVector : public Debayer
{
	public:
		DebayerGreyscaleVector(){}
		enum EnOscPictureType getType();
		GreyscaleImage* getObject(uint16 width, uint16 height);
		bool debayer(RawImage* raw, Image* image);
};

#endif
