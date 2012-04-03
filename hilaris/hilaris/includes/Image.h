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
		
		// from http://www.gotw.ca/publications/mill18.htm
		// Guideline #4: A base class destructor should be either public and virtual, or protected and nonvirtual.
		virtual ~Image();
		
		OSC_PICTURE& getOscarContext();
		void setOscarContext();
		void save(char* path, enum ImageEncoding enc = BMP);
		
		uint16 getWidth();
		uint16 getHeight();
		
		virtual uint8* getDataPtr() = 0;
		virtual EnOscPictureType getType() = 0;		
		
	protected:		
		uint16 width;
		uint16 height;
		
		enum EnOscPictureType type;
		OSC_PICTURE oscarContext;
};

#endif 
