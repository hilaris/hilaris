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

Image::~Image()
{

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
	this->debayer();
	
	struct OSC_PICTURE pic;
	
	pic.width = this->width;
	pic.height = this->height;
	pic.type = this->type;
	pic.data = this->data;
	
	return pic;
}

bool Image::debayer()
{
	enum EnBayerOrder order;
	OscCamGetBayerOrder(&order,0,0);
	
	OscVisDebayer(this->rawData, this->width, this->height, order, this->data);
	
	return true;
}

bool Image::filter(struct OSC_VIS_FILTER_KERNEL *kernel)
{
	if(!this->toGreyscale())
	{
		return false;
	}
	
	OSC_ERR err;
	OSC_PICTURE picIn = this->getOscarContext();
	OSC_PICTURE picOut;
	uint8 outData[this->width * this->height * 3];
	
	picOut.data = outData;
	uint8 pTemp[this->width * this->height * 3];
	
	if((err = OscVisFilter2D(&picIn, &picOut, pTemp, kernel)) != SUCCESS)
	{
		return false;
	}
	
	memcpy(this->data, picOut.data, this->width * this->height * 3 * sizeof(uint8));
	
	return true;
}

bool Image::erode(struct OSC_VIS_STREL *strel, uint8 repetitions)
{
	if(!this->toBinary())
	{
		return false;
	}
	
	OSC_ERR err;
	OSC_PICTURE picIn = this->getOscarContext();
	OSC_PICTURE picOut;
	uint8 outData[this->width * this->height * 3];
	
	picOut.data = outData;
	uint8 pTemp[this->width * this->height * 3];
	
	if((err = OscVisErode(&picIn, &picOut, pTemp, strel, repetitions)) != SUCCESS)
	{
		return false;
	}
	
	memcpy(this->data, picOut.data, this->width * this->height * 3 * sizeof(uint8));
	
	return true;
}

bool Image::dilate(struct OSC_VIS_STREL *strel, uint8 repetitions)
{
	if(!this->toBinary())
	{
		return false;
	}
	
	OSC_ERR err;
	OSC_PICTURE picIn = this->getOscarContext();
	OSC_PICTURE picOut;
	uint8 outData[this->width * this->height * 3];
	
	picOut.data = outData;
	uint8 pTemp[this->width * this->height * 3];
	
	if((err = OscVisDilate(&picIn, &picOut, pTemp, strel, repetitions)) != SUCCESS)
	{
		return false;
	}
	
	memcpy(this->data, picOut.data, this->width * this->height * 3 * sizeof(uint8));
	
	return true;
}

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
	
	memcpy(this->data, picOut.data, this->width * this->height * 3 * sizeof(uint8));
	this->type = picOut.type;
	
	return true;
}

bool Image::toGreyscale()
{
	if(this->type == OSC_PICTURE_GREYSCALE)
	{
		return true;
	}
	
	OSC_ERR err;
	OSC_PICTURE picIn = this->getOscarContext();
	OSC_PICTURE picOut;
	
	uint8 outData[this->width * this->height * 3];
	picOut.data = outData;
	
	if(this->type == OSC_PICTURE_BGR_24)
	{
		if((err = OscVisBGR2Grey(&picIn, &picOut)) != SUCCESS)
		{
			return false;
		}
	}
	
	memcpy(this->data, picOut.data, this->width * this->height * 3 * sizeof(uint8));
	this->type = picOut.type;
	
	return true;
}
