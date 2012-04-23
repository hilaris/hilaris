#ifndef _LINE_H_
#define _LINE_H_

#include "leanXoverlay.h"
#include "DrawableObject.h"

class Line : public DrawableObject
{
	public:
		Line(uint16 x1, uint16 y1, uint16 x2, uint16 y2, uint32 color) : x1(x1), x2(x2), y1(y1), y2(y2), color(color) {}
		~Line() {}
		
		void draw(Image* image);
		
	private:
	
		uint16 x1;
		uint16 x2;
		uint16 y1;
		uint16 y2;
		uint32 color;
};

#endif
