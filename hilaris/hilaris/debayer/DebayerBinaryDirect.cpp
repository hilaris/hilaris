#include "DebayerBinaryDirect.h"

EnOscPictureType DebayerBinaryDirect::getType()
{
	return OSC_PICTURE_BINARY;
}

long unsigned int DebayerBinaryDirect::getSize()
{
	return sizeof(BinaryImage);
}

BinaryImage* DebayerBinaryDirect::getObject(uint16 width, uint16 height)
{
	return new BinaryImage(width/2, height/2);
}

bool DebayerBinaryDirect::debayer(RawImage* raw, Image* image)
{	
	return raw->debayerFast((BinaryImage*)image, this->threshold, this->blackIsForegound);
}

