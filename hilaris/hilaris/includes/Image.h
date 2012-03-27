#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "Hilaris.h"

class Image {
	friend class Camera;

	public:
		Image(uint16 width, uint16 height, enum EnOscPictureType type);
		~Image();
		
		OSC_PICTURE getOscarContext();
	
	private:
		uint8* rawData;
		uint8* data;
		uint16 width;
		uint16 height;
		enum EnOscPictureType type;
		
};

#endif 
