#ifndef _TEXT_H_
#define _TEXT_H_

#include <string.h>

#include "oscar.h"
#include "leanXoverlay.h"
#include "DrawableObject.h"
#include "Image.h"

/**
 *  @brief Draw Text to an Image.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since April 2012
 */
class Text : public DrawableObject
{
	public:
	    /**
		 *  @brief Constructor for creating Text.
		 *
		 *  @param x X-Component of the start point.
		 *  @param y Y-Component of the start point.
		 *  @param size The size of the text. 1 is the smallest possible value, but readable.
		 *  @param text The text which should be drawn to the Image.
		 *  @param fgColor A uint32 representing the foreground color.
		 *  @param bgColor A uint32 representing the background color.
		 */
		Text(uint16 x, uint16 y, uint8 size, const char* text, uint32 fgColor, uint32 bgColor);
		~Text() {}
		
		/**
		 *  @brief Draw this Text to the given Image.
		 *
		 *  @param image Draw the Text to this Image.
		 */
		void draw(Image* image);
		
		/**
		 *  @brief Changes the text of a text drawable
		 *
		 *  @param text The text which should be drawn to the Image.
		 */
		void setText(char* text);
		
	private:
	
		uint16 x;
		uint16 y;
		uint8 size;
		
		char text[256];
		
		uint32 fgColor;
		uint32 bgColor;
};

#endif
