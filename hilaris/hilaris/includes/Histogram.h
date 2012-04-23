#ifndef _HISTOGRAM_H_
#define _HISTOGRAM_H_

#include <math.h>

class GreyscaleImage;

#include "oscar.h"
#include "GreyscaleImage.h"

class Histogram
{
	public:
		Histogram(GreyscaleImage* grey);
		
		void init(void);
		void equalize(void);
	
	private:
		
		int& value(int key);
		int cdf(int key);
	
		GreyscaleImage* image;
		bool initialized;
		int data[256];
};

#endif
