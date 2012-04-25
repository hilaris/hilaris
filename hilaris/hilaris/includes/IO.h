#ifndef _IO_H_
#define _IO_H_

#include "oscar.h"
#include "Led.h"

/**
 *  @brief Access layer to GPIO (General Purpose Input/Output)
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since April 2012
 */
class IO
{
	public:
		
		/**
		 *  @brief The Pins which can be addressed.
		 *  @todo These are only the pins on the leanXcam, not on the leanXradio.
		 *   Maybe we could fix this.
		 */
		enum Pin
		{
			IN1 = 4,
			IN2 = 7,
			OUT1 = 2,
			OUT2 = 6
		};
		
		IO();
		~IO();
		
		/**
		 *  @brief Write a boolean value to a specific Pin.
		 *  
		 *  @param pin The Pin where to write to.
		 *  @param active The value which should be written.
		 *
		 *  @return Success state.
		 */
		bool write(enum IO::Pin pin, bool active);
		
		/**
		 *  @brief Read from a Pin.
		 *
		 *  @param pin Where to read from.
		 *  @return The state of the Pin, aka. the value.
		 */
		bool read(enum IO::Pin pin);
		
		/**
		 *  @brief Set the polarity of a Pin.
		 *
		 *  @param pin The Pin where to set the polarity.
		 *  @param lowActive True if the Pin should be lowActive, false otherwise.
		 */
		bool setPolarity(enum IO::Pin pin, bool lowActive);
		
		/**
		 *  @brief Get the Led instance of the leanXcam.
		 *  @return Pointer to the Led.
		 */
		Led* led();
	
	private:
		enum EnGpios getOscarIO(enum IO::Pin pin);
		
		Led* testLed;
};

#endif
