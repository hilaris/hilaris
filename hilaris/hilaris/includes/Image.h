#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "Hilaris.h"

enum ImageEncoding 
{
	BMP, JPG
};

class Image {
	friend class Camera;
	friend class StreamServer;

	public:
		Image(uint16 width, uint16 height, enum EnOscPictureType type);
		~Image();
		
		OSC_PICTURE getOscarContext();
		void save(char* path, enum ImageEncoding enc = BMP);
		bool filter(struct OSC_VIS_FILTER_KERNEL *kernel);
		bool dilate(struct OSC_VIS_STREL *strel, uint8 repetitions);
		bool erode(struct OSC_VIS_STREL *strel, uint8 repetitions);
		
		bool toBinary(uint8 thresold = 64, bool invert = false);
		bool toGreyscale();
	
	private:
		uint8* rawData;
		uint8* data;
		uint16 width;
		uint16 height;
		enum EnOscPictureType type;
		
		bool debayer();
};

#endif 
