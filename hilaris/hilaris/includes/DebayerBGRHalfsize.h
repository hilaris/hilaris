#ifndef _DEBAYERBGRHALFSIZE_H_
#define _DEBAYERBGRHALFSIZE_H_

#include "Debayer.h"
#include "BGRImage.h"
#include "BGRImageFactory.h"

#include <string.h>

class DebayerBGRHalfsize : public Debayer
{
	public:
		DebayerBGRHalfsize(){}
		enum EnOscPictureType getType();
		BGRImage* getObject(uint16 width, uint16 height);
		bool debayer(RawImage* raw, Image* image);
		long unsigned int getSize();
		
		virtual ~DebayerBGRHalfsize() {};
};

#endif
