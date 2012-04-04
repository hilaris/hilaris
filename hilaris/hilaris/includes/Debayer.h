#ifndef _DEBAYER_H_
#define _DEBAYER_H_

#include "Image.h"
#include "RawImage.h"

class Debayer
{
	public:
		virtual enum EnOscPictureType getType() = 0;
		virtual Image* getObject(uint8 width, uint8 height) = 0;
		virtual bool debayer(RawImage* raw, Image* image) = 0;
	protected:
		Debayer(){}
};

#endif
