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
	this->debayer();
	
	struct OSC_PICTURE pic;
	
	pic.width = this->width;
	pic.height = this->height;
	pic.type = this->type;
	pic.data = this->data;
	
	return pic;
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
	struct OSC_PICTURE pic;
	pic = this->getOscarContext();
	
	if(enc==BMP)
	{
		OSC_ERR err;
		err = OscBmpWrite(&pic, path);
		if(err!=SUCCESS)
			OscLog(DEBUG, "Error: %d\n", err);
		else
			OscLog(DEBUG, "Saved to: %s\n", path);
	}
	else if(enc==JPG)
	{
		//TODO JPG Encoding
		OscBmpWrite(&pic, path);
	}
	else
	{
		//TODO throw appropriate exception
		throw 1;
	}
}

bool Image::debayer()
{
	enum EnBayerOrder order;
	OscCamGetBayerOrder(&order,0,0);
	
	OscVisDebayer(this->rawData, this->width, this->height, order, this->data);
	
	return true;
}
