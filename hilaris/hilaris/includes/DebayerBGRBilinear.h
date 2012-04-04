#ifndef _DEBAYERBGRBILINEAR_H_
#define _DEBAYERBGRBILINEAR_H_

#include "Debayer.h"
#include "BGRImage.h"
#include "BGRImageFactory.h"

#include <string.h>

class DebayerBGRBilinear : public Debayer
{
	public:
		DebayerBGRBilinear(){}
		enum EnOscPictureType getType();
		BGRImage* getObject(uint16 width, uint16 height);
		bool debayer(RawImage* raw, Image* image);
};

#endif
