#ifndef _DRAWABLE_OBJECT_H_
#define _DRAWABLE_OBJECT_H_

class Image;

class DrawableObject
{
	public:
		virtual void draw(Image* image) = 0;
};

#endif
