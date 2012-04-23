#include "Line.h"

void Line::draw(Image* image)
{
	ov_line(&image->getOscarContext(), this->x1, this->y1, this->x2, this->y2, this->color);
}
