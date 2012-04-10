#ifndef _DEBAYERBGRBILINEAR_H_
#define _DEBAYERBGRBILINEAR_H_

#include "Hilaris.h"

#include <string.h>

class DebayerBGRBilinear : public Debayer
{
	public:
		DebayerBGRBilinear(){}
		enum EnOscPictureType getType();
		BGRImage* getObject(uint16 width, uint16 height);
		bool debayer(RawImage* raw, Image* image);
		long unsigned int getSize();
		
		virtual ~DebayerBGRBilinear() {};
};

#endif
