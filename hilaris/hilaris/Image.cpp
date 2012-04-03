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
	
	if(enc == BMP)
	{
		OSC_ERR err;
		
		if((err = OscBmpWrite(&pic, path)) != SUCCESS)
		{
			OscLog(DEBUG, "Error saving file: %d\n", err);
		}
	}
}

OSC_PICTURE Image::getOscarContext()
{
	struct OSC_PICTURE pic;
	
	pic.width = this->width;
	pic.height = this->height;
	pic.type = this->getType();
	pic.data = this->getDataPtr();
	
	return pic;
}

/*

bool Image::toBinary(uint8 threshold, bool invert)
{
	if(this->type == OSC_PICTURE_BINARY)
	{
		return true;
	}
	
	OSC_ERR err;
	OSC_PICTURE picIn = this->getOscarContext();
	OSC_PICTURE picOut;
	
	uint8 outData[this->width * this->height * 3];
	picOut.data = outData;
	
	if(this->type == OSC_PICTURE_GREYSCALE)
	{
		if((err = OscVisGrey2BW(&picIn, &picOut, threshold, invert)) != SUCCESS)
		{
			return false;
		}
	}
	
	if(this->type == OSC_PICTURE_BGR_24)
	{
		if((err = OscVisBGR2BW(&picIn, &picOut, threshold, invert)) != SUCCESS)
		{
			return false;
		}
	}
	
	memcpy(this->data, picOut.data, this->width * this->height * sizeof(uint8));
	this->type = picOut.type;
	
	return true;
}

bool Image::toGreyscale()
{
	if(this->type == OSC_PICTURE_GREYSCALE)
	{
		return true;
	}
	
	// this is a little bit of a hack
	// but due to bmp-save limitation of oscar
	// its necessary
	if(this->type == OSC_PICTURE_BINARY)
	{
		this->type = OSC_PICTURE_GREYSCALE;
		return true;
	}
	
	OSC_ERR err;
	OSC_PICTURE picIn = this->getOscarContext();
	OSC_PICTURE picOut;
	
	uint8 outData[this->width * this->height * sizeof(uint8)];
	picOut.data = outData;
	
	if(this->type == OSC_PICTURE_BGR_24)
	{
		if((err = OscVisBGR2Grey(&picIn, &picOut)) != SUCCESS)
		{
			return false;
		}
	}
	
	memcpy(this->data, picOut.data, this->width * this->height * sizeof(uint8));
	this->type = picOut.type;
	
	return true;
}

*/
