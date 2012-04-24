#include "DrawableObject.h"

bool DrawableObject::init = false;

DrawableObject::DrawableObject()
{
	if(!DrawableObject::init)
	{
		ov_init();
		DrawableObject::init = true;
		OscLog(DEBUG, "Initialized Overlay!\n");
	}
}
