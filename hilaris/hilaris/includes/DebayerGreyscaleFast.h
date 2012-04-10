#ifndef _DEBAYERGREYSCALEFAST_H_
#define _DEBAYERGREYSCALEFAST_H_

#include "Hilaris.h"

#include <string.h>

class DebayerGreyscaleFast : public Debayer
{
	public:
		DebayerGreyscaleFast(){}
		enum EnOscPictureType getType();
		GreyscaleImage* getObject(uint16 width, uint16 height);
		bool debayer(RawImage* raw, Image* image);
		long unsigned int getSize();
		
		virtual ~DebayerGreyscaleFast() {};
};

#endif
