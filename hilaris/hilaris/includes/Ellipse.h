#ifndef _ELLIPSE_H_
#define _ELLIPSE_H_

#include "oscar.h"
#include "leanXoverlay.h"
#include "DrawableObject.h"
#include "Image.h"

/**
 *  @brief An Ellipse, which can be drawn to an Image.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since April 2012
 */
class Ellipse : public DrawableObject
{
	public:
		
		/**
		 *  @brief Constructor for creating an Ellipse.
		 *
		 *  @param x1 X-Component of the left upper corner of the imagenary surrounding box.
		 *  @param y1 Y-Component of the left upper corner of the imagenary surrounding box.
		 *  @param x2 X-Component of the lower right corner of the imagenary surrounding box.
		 *  @param y2 Y-Component of the lower right corner of the imagenary surrounding box.
		 *  @param color A uint32 representing a color.
		 *  @param fill Should the box be filled while drawing.
		 */
		Ellipse(uint16 x1, uint16 y1, uint16 x2, uint16 y2, uint32 color, bool fill = false) : x1(x1), x2(x2), y1(y1), y2(y2), color(color), fill(fill) {}
		~Ellipse() {}
		
		/**
		 *  @brief Draw this Ellipse to the given Image.
		 *
		 *  @param image Draw the Ellipse to this Image.
		 */
		void draw(Image* image);
	
		/**
		 *	@brief X-Component of the left upper corner of the imagenary surrounding box.
		 */
		uint16 x1;
		
		/**
		 *	@brief Y-Component of the left upper corner of the imagenary surrounding box.
		 */
		uint16 x2;
		
		/**
		 *	@brief X-Component of the lower right corner of the imagenary surrounding box.
		 */
		uint16 y1;
		
		/**
		 *	@brief Y-Component of the lower right corner of the imagenary surrounding box.
		 */
		uint16 y2;
		
		/**
		 *	@brief A uint32 representing a color.
		 */
		uint32 color;
		
		/**
		 *	@brief Should the box be filled while drawing.
		 */
		bool fill;
};

#endif
