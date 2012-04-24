#ifndef _ELLIPSE_H_
#define _ELLIPSE_H_

#include "oscar.h"
#include "leanXoverlay.h"
#include "DrawableObject.h"
#include "Image.h"

class Ellipse : public DrawableObject
{
	public:
		Ellipse(uint16 x1, uint16 y1, uint16 x2, uint16 y2, uint32 color, bool fill = false) : x1(x1), x2(x2), y1(y1), y2(y2), color(color), fill(fill) {}
		~Ellipse() {}
		
		void draw(Image* image);
	
		uint16 x1;
		uint16 x2;
		uint16 y1;
		uint16 y2;
		uint32 color;
		bool fill;
};

#endif
