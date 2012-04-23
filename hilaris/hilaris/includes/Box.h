#ifndef _BOX_H_
#define _BOX_H_

#include "oscar.h"
#include "leanXoverlay.h"
#include "DrawableObject.h"
#include "Image.h"

class Box : public DrawableObject
{
	public:
		Box(uint16 x1, uint16 y1, uint16 x2, uint16 y2, uint32 color, bool fill = false) : x1(x1), x2(x2), y1(y1), y2(y2), color(color), fill(fill) {}
		~Box() {}
		
		void draw(Image* image);
		
	private:
	
		uint16 x1;
		uint16 x2;
		uint16 y1;
		uint16 y2;
		uint32 color;
		bool fill;
};

#endif
