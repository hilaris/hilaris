#ifndef _DEBAYERBGRFAST_H_
#define _DEBAYERBGRFAST_H_

#include <string.h>

#include "oscar.h"
#include "Image.h"
#include "RawImage.h"
#include "BGRImage.h"
#include "BGRImageFactory.h"
#include "Debayer.h"

/**
 *  @brief Bilinear Debayer for BGRImage.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 */
class DebayerBGRFast : public Debayer
{
	public:
		enum EnOscPictureType getType();
		BGRImage* getObject(uint16 width, uint16 height);
		bool debayer(RawImage* raw, Image* image);
		long unsigned int getSize();
		
		DebayerBGRFast(){}
		virtual ~DebayerBGRFast() {};
};

#endif
