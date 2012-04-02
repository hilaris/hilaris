#include "GreyscaleImage.h"

/*
bool GreyscaleImage::debayer()
{
	return true;
}

bool GreyscaleImage::filter(struct OSC_VIS_FILTER_KERNEL *kernel)
{
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
	
	memcpy(this->data, picOut.data, this->width * this->height * sizeof(uint8));
	
	return true;
}
*/
