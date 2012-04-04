#ifndef _DEBAYERBGRSTANDARD_H_
#define _DEBAYERBGRSTANDARD_H_

#include "Debayer.h"
#include "BGRImage.h"
#include "BGRImageFactory.h"

#include <string.h>

class DebayerBGRStandard : public Debayer
{
	public:
		DebayerBGRStandard(){}
		enum EnOscPictureType getType();
		BGRImage* getObject(uint16 width, uint16 height);
		bool debayer(RawImage* raw, Image* image);
};

#endif
