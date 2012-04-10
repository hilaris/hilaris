#ifndef _DEBAYERGREYSCALEHALFSIZE_H_
#define _DEBAYERGREYSCALEHALFSIZE_H_

#include "Hilaris.h"

#include <string.h>

class DebayerGreyscaleHalfsize : public Debayer
{
	public:
		DebayerGreyscaleHalfsize(){}
		enum EnOscPictureType getType();
		GreyscaleImage* getObject(uint16 width, uint16 height);
		bool debayer(RawImage* raw, Image* image);
		long unsigned int getSize();
		
		virtual ~DebayerGreyscaleHalfsize() {}
};

#endif
