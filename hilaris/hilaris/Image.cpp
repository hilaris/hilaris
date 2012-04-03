#include "Image.h"

Image::Image(uint16 width, uint16 height)
{
	// store data
	this->width  = width;
	this->height = height;
}

Image::Image()  { }
Image::~Image() { }	

uint16 Image::getWidth()
{
	return this->width;
}

uint16 Image::getHeight()
{
	return this->height;
}

/**
 *  @brief Save an image to the given path.
 *
 *  @param path The location where the image should be stored.
 *  @param enc  The image encoder which should be used. i.e: BMP, JPG
 *
 *  @warning This will not save the whole class, but just its debayered data as an image file.
 */
void Image::save(char* path, enum ImageEncoding enc)
{
	struct OSC_PICTURE pic = this->getOscarContext();
	
	this->saveContext(pic, path);
}

void Image::saveContext(struct OSC_PICTURE pic, char* path)
{
	OSC_ERR err;
	
	if((err = OscBmpWrite(&pic, path)) != SUCCESS)
	{
		OscLog(DEBUG, "Error saving file: %d\n", err);
	}
}

OSC_PICTURE& Image::getOscarContext()
{
	this->setOscarContext();
	return this->oscarContext;
}

void Image::setOscarContext()
{	
	this->oscarContext.width  = this->getWidth();
	this->oscarContext.height = this->getHeight();
	this->oscarContext.type   = this->getType();
	this->oscarContext.data   = this->getDataPtr();
}

