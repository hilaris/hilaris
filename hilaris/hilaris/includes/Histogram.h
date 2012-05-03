#ifndef _HISTOGRAM_H_
#define _HISTOGRAM_H_

#include <math.h>

class GreyscaleImage;

#include "oscar.h"
#include "GreyscaleImage.h"

/**
 *  @brief The Histogram for a GreyscaleImage.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 *
 *  @todo Getter for values of the histogram
 */
class Histogram
{
	public:
		/**
		 *  @brief Constructor for Histrogram.
		 *  @param grey The GreyscaleImage for this Histogram.
		 */
		Histogram(GreyscaleImage* grey);
		
		/**
		 *  @brief Initialize the Histogram for the given GreyscaleImage.
		 *
		 *  Will be automatically called if this function is retrieved from a
		 *  GreyscaleImage.
		 *
		 *  @see GreyscaleImage::histogram()
		 */
		void init(void);
		
		/**
		 *  @brief Equalize this Histogram.
		 *
		 *  This function will not only equalize the data of the Histogram for you,
		 *  but write down the equalized data to the given GreyscaleImage.
		 *  This makes the equalization of an Image as easy as a call for this
		 *  function.
		 */
		void equalize(void);
	
	private:
		
		int& value(int key);
		int cdf(int key);
	
		GreyscaleImage* image;
		bool initialized;
		int data[256];
};

#endif
