#ifndef _DEBAYERBGRFAST_H_
#define _DEBAYERBGRFAST_H_

#include <string.h>

#include "oscar.h"
#include "Image.h"
#include "RawImage.h"
#include "BGRImage.h"
#include "BGRImageFactory.h"
#include "Debayer.h"

class DebayerBGRFast : public Debayer
{
	public:
		DebayerBGRFast(){}
		enum EnOscPictureType getType();
		BGRImage* getObject(uint16 width, uint16 height);
		bool debayer(RawImage* raw, Image* image);
		long unsigned int getSize();
		
		virtual ~DebayerBGRFast() {};
};

#endif
