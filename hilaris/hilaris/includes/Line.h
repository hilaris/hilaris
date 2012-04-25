#ifndef _LINE_H_
#define _LINE_H_

#include "oscar.h"
#include "leanXoverlay.h"
#include "DrawableObject.h"
#include "Image.h"

/**
 *  @brief A Line, which can be drawn to an Image.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since April 2012
 */
class Line : public DrawableObject
{
	public:
		
		/**
		 *  @brief Constructor for creating a Line.
		 *
		 *  @param x1 X-Component of the start point.
		 *  @param y1 Y-Component of the start point.
		 *  @param x2 X-Component of the end point.
		 *  @param y2 Y-Component of the end point.
		 *  @param color A uint32 representing a color.
		 */
		Line(uint16 x1, uint16 y1, uint16 x2, uint16 y2, uint32 color) : x1(x1), x2(x2), y1(y1), y2(y2), color(color) {}
		~Line() {}
		
		/**
		 *  @brief Draw this Box to the given Image.
		 *
		 *  @param image Draw the Line to this Image.
		 */
		void draw(Image* image);
		
	private:
	
		uint16 x1;
		uint16 x2;
		uint16 y1;
		uint16 y2;
		uint32 color;
};

#endif
