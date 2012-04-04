#ifndef _DEBAYERBGRFAST_H_
#define _DEBAYERBGRFAST_H_

#include "Debayer.h"
#include "BGRImage.h"
#include "BGRImageFactory.h"

class DebayerBGRFast : public Debayer
{
	public:
		DebayerBGRFast(){}
		
		bool debayer(RawImage* raw, Image* image);
};

#endif
