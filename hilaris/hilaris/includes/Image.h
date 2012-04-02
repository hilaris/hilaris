#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "oscar.h"

enum ImageEncoding 
{
	BMP, JPG
};

class Image {

	public:
		Image();
		Image(uint16 width, uint16 height);
		~Image();
		
		OSC_PICTURE getOscarContext();
		void save(char* path, enum ImageEncoding enc = BMP);
		
		uint16 getWidth();
		uint16 getHeight();
		uint8* getDataPtr();
		
		virtual EnOscPictureType getType() = 0;
		
	protected:
		uint8* data;
		uint16 width;
		uint16 height;
		
		enum EnOscPictureType type;
};

#endif 
