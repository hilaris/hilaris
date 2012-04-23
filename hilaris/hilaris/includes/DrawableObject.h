#ifndef _DRAWABLE_OBJECT_H_
#define _DRAWABLE_OBJECT_H_

#include "Image.h"

class DrawableObject
{
	public:
		virtual void draw(Image* image) = 0;
};

#endif
