#include "Text.h"

void Text::draw(Image* image)
{
	ov_text(&image->getOscarContext(), this->x, this->y, this->size, this->text, this->fgColor, this->bgColor);
}

Text::Text(uint16 x, uint16 y, uint8 size, const char* text, uint32 fgColor, uint32 bgColor) : x(x), y(y), size(size), fgColor(fgColor), bgColor(bgColor)
{
	strcpy(this->text, text);
}
