#ifndef _TEXT_H_
#define _TEXT_H_

#include <string.h>

#include "oscar.h"
#include "leanXoverlay.h"
#include "DrawableObject.h"
#include "Image.h"

class Text : public DrawableObject
{
	public:
		Text(uint16 x, uint16 y, uint8 size, const char* text, uint32 fgColor, uint32 bgColor);
		~Text() {}
		
		void draw(Image* image);
		
	private:
	
		uint16 x;
		uint16 y;
		uint8 size;
		
		char text[256];
		
		uint32 fgColor;
		uint32 bgColor;
};

#endif
