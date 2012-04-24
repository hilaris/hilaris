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
	// do the debayering
	uint8 bg = false ? 255 : 0;
	uint8 fg = false ? 0 : 255;
	
	uint16 x,y;
	uint32 outPos=0;
	uint8 *in  = (uint8 *)raw->getDataPtr();
	uint8 *out = (uint8 *)image->getDataPtr();

	for (y=0; y<raw->getHeight(); y += 2)
	{
		for (x=0; x<raw->getWidth(); x += 2)
		{
			out[outPos++] = ((uint8)
			(
				(
					(uint16)in[y*raw->getWidth()+x]       + 
					(uint16)in[y*raw->getWidth()+x+1]     + 
					(uint16)in[(y+1)*raw->getWidth()+x]   +
					(uint16)in[(y+1)*raw->getWidth()+x+1]
				)
			>> 2)) >= 100 ? fg : bg;
		}
	}
	
	return true;
}

