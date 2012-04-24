#ifndef _OVERLAY_H_
#define _OVERLAY_H_

#include <vector>

#include "DrawableObject.h"

class Overlay
{
	private:
		std::vector<DrawableObject*> objects;
	public:
		void addObject(DrawableObject* object);
		int size();
		void pop();
		DrawableObject* get(int i);
};

#endif
