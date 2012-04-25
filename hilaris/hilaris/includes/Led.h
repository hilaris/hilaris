#ifndef _LED_H_
#define _LED_H_

#include "oscar.h"

/**
 *  @brief The test Led on the leanXcam.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since April 2012
 */
class Led
{
	public:
	
		Led();
		~Led();
		
		/**
		 *  @brief Set the color of this Led.
		 *
		 *  @param red Red color component.
		 *  @param green Green color component.
		 *  
		 *  @return Success state.
		 */
		bool setColor(uint8 red, uint8 green);
		
		/**
		 *  @brief Turn this Led on.
		 *  @return Success state.
		 */
		bool on();
		
		/**
		 *  @brief Turn this Led on with a specific color.
		 *
		 *  @param red Red color component.
		 *  @param green Green color component.
		 *
		 *  @return Success state.
		 */
		bool on(uint8 red, uint8 green);
		
		/**
		 *  @brief Turn this Led off.
		 *  @return Success state.
		 */
		bool off();
		
		/**
		 *  @brief Toggle this Led.
		 *
		 *  If it was turned on, it will turn off and vice versa.
		 *
		 *  @return Success state.
		 */
		bool toggle();
	
	private:
	
		uint8 red;
		uint8 green;
};

#endif
