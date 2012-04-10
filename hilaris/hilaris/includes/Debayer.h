#ifndef _DEBAYER_H_
#define _DEBAYER_H_

#include "oscar.h"
#include "Image.h"

class Debayer
{
	public:
		virtual enum EnOscPictureType getType() = 0;
		virtual Image* getObject(uint16 width, uint16 height) = 0;
		virtual bool debayer(RawImage* raw, Image* image) = 0;
		virtual long unsigned int getSize() = 0;
		
		virtual ~Debayer() {};
		
	protected:
		Debayer(){}
};

#endif
