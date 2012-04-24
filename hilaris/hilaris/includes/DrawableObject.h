#ifndef _DRAWABLE_OBJECT_H_
#define _DRAWABLE_OBJECT_H_

class Image;

#include "leanXoverlay.h"

class DrawableObject
{
	public:
		virtual void draw(Image* image) = 0;
		static bool init;
		// from http://www.gotw.ca/publications/mill18.htm
		// Guideline #4: A base class destructor should be either public and virtual, or protected and nonvirtual.
		virtual ~DrawableObject(){}
		DrawableObject();
};

#endif
