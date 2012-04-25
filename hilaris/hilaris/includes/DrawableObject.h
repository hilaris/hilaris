#ifndef _DRAWABLE_OBJECT_H_
#define _DRAWABLE_OBJECT_H_

class Image;

#include "leanXoverlay.h"

class DrawableObject
{
	public:
		/**
		 *  @brief Draw this Object to the Overlay.
		 *
		 *  @param image A pointer to the Image where it should be drawn to.
		 */
		virtual void draw(Image* image) = 0;
		
		/**
		 *  @brief Initialize drawing.
		 *
		 *  This is used to initialize the Oscar internal ressources which
		 *  are used for drawing. This is for example the Font_System.bmp.
		 *
		 *  @return Success state.
		 */
		static bool init;
		
		// from http://www.gotw.ca/publications/mill18.htm
		// Guideline #4: A base class destructor should be either public and virtual, or protected and nonvirtual.
		virtual ~DrawableObject(){}
		DrawableObject();
};

#endif
