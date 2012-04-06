#ifndef _DEBAYERBGRFAST_H_
#define _DEBAYERBGRFAST_H_

#include "Debayer.h"
#include "BGRImage.h"
#include "BGRImageFactory.h"

#include <string.h>

class DebayerBGRFast : public Debayer
{
	public:
		DebayerBGRFast(){}
		enum EnOscPictureType getType();
		BGRImage* getObject(uint16 width, uint16 height);
		bool debayer(RawImage* raw, Image* image);
		long unsigned int getSize();
};

#endif
