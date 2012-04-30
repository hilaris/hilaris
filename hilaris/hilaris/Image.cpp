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

void Image::copyData(uint8* data)
{
	memcpy(this->getDataPtr(), data, this->width * this->height * (OSC_PICTURE_TYPE_COLOR_DEPTH(this->getType())/8));
}

void Image::save(const char* path, enum ImageEncoding enc)
{
	struct OSC_PICTURE pic = this->getOscarContext();
	
	this->saveContext(pic, path);
}

void Image::saveContext(struct OSC_PICTURE pic, const char* path)
{
	OSC_ERR err;
	
	if((err = OscBmpWrite(&pic, path)) != SUCCESS)
	{
		Debug::log(Debug::DEBUG, "%s:\t Error saving file: %d\n", __func__, err);
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

void Image::drawOverlay(Overlay* overlay)
{
	for(int i=0;i<overlay->size();i++)
	{
		overlay->get(i)->draw(this);
	}
}

void Image::drawObject(DrawableObject* object)
{
	object->draw(this);
}
