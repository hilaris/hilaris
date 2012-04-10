#ifndef _DEBAYERBGRSTANDARD_H_
#define _DEBAYERBGRSTANDARD_H_

#include "Hilaris.h"

#include <string.h>

class DebayerBGRStandard : public Debayer
{
	public:
		DebayerBGRStandard(){}
		enum EnOscPictureType getType();
		BGRImage* getObject(uint16 width, uint16 height);
		bool debayer(RawImage* raw, Image* image);
		long unsigned int getSize();
		
		virtual ~DebayerBGRStandard() {};
};

#endif
