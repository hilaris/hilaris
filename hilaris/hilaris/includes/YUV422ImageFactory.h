#ifndef _YUV422IMAGEFACTORY_H_
#define _YUV422IMAGEFACTORY_H_

class YUV422Image;

#include "oscar.h"
#include "YUV422Image.h"
#include "RawImage.h"

/**
 *  @brief An Image factory for retrieving a YUV422Image.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 */
class YUV422ImageFactory
{
	public:
	
		static YUV422Image getFastDebayered(RawImage* raw);
};

#endif
