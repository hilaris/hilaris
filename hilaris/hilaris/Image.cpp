#include "Image.h"

Image::Image(uint16 width, uint16 height, enum EnOscPictureType type)
{
	// store data
	this->width  = width;
	this->height = height;
	this->type   = type;
	
	// create arrays
	this->rawData = new uint8[width * height];
	this->data    = new uint8[width * height * 3];
}

OSC_PICTURE Image::getOscarContext()
{
	// todo: debayer!	
	struct OSC_PICTURE pic;
	
	pic.width = this->width;
	pic.height = this->height;
	pic.type = this->type;
	pic.data = this->data;
	
	return pic;
}
