#ifndef _OVERLAY_H_
#define _OVERLAY_H_

#include <vector>

#include "DrawableObject.h"

/**
 *  @brief An Overlay contains a bunch of DrawableObject and can be drawn to an Image.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since April 2012
 */
class Overlay
{
	public:
	
		/**
		 *  @brief Add a new DrawableObject to this Overlay.
		 *  @param object A pointer to the DrawableObject.
		 */
		void addObject(DrawableObject* object);
		
		/**
		 *  @brief Get the number of DrawableObject elements on this Overlay.
		 *  @return The size of this Overlay.
		 */
		int size();
		
		/**
		 *  @brief Pops the next DrawableObject.
		 *  @todo A bit more sense please :D
		 */
		void pop();
		
		/**
		 *  @brief Get a specific DrawableObject which is bound to this Overlay.
		 *
		 *  @param i The index.
		 *  @return The pointer to the DrawableObject.
		 */
		DrawableObject* get(int i);
		
	private:
	
		std::vector<DrawableObject*> objects;
};

#endif
