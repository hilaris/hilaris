#include "Overlay.h"

void Overlay::addObject(DrawableObject* object)
{
	this->objects.push_back(object);
}

int Overlay::size()
{
	return this->objects.size();
}

DrawableObject* Overlay::get(int i)
{
	return this->objects.at(i);
}

void Overlay::pop()
{
	this->objects.erase(this->objects.begin());
}
