#include "Ellipse.h"

void Ellipse::draw(Image* image)
{
	ov_ellipse(&image->getOscarContext(), this->x1, this->y1, this->x2, this->y2, this->color, this->fill);
}
