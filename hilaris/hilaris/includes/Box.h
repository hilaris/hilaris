#ifndef _BOX_H_
#define _BOX_H_

#include "oscar.h"
#include "leanXoverlay.h"
#include "DrawableObject.h"
#include "Image.h"

/**
 *  @brief A Box, which can be drawn to an Image.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since April 2012
 */
class Box : public DrawableObject
{
	public:
		
		/**
		 *  @brief Constructor for creating a Box.
		 *
		 *  @param x1 X-Component of the left upper corner.
		 *  @param y1 Y-Component of the left upper corner.
		 *  @param x2 X-Component of the lower right corner.
		 *  @param y2 Y-Component of the lower right corner.
		 *  @param color A uint32 representing a color.
		 *  @param fill Should the box be filled while drawing.
		 */
		Box(uint16 x1, uint16 y1, uint16 x2, uint16 y2, uint32 color, bool fill = false) : x1(x1), x2(x2), y1(y1), y2(y2), color(color), fill(fill) {}
		~Box() {}
		
		/**
		 *  @brief Draw this Box to the given Image.
		 *
		 *  @param image Draw the Box to this Image.
		 */
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
