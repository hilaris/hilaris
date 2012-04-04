#ifndef _DEBAYER_H_
#define _DEBAYER_H_

#include "Image.h"
#include "RawImage.h"

class Debayer
{
	public:
		virtual bool debayer(RawImage* raw, Image* image) = 0;
	protected:
		Debayer(){}
};

#endif
