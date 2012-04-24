#include "Box.h"

void Box::draw(Image* image)
{
	ov_init();
	ov_box(&image->getOscarContext(), this->x1, this->y1, this->x2, this->y2, this->color, this->fill);
}
