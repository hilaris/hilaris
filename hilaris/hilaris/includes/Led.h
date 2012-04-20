#ifndef _LED_H_
#define _LED_H_

#include "oscar.h"

class Led
{
	public:
		Led();
		~Led();
		bool setColor(uint8 red, uint8 green);
		bool on();
		bool on(uint8 red, uint8 green);
		bool off();
		bool toggle();
	
	private:
		uint8 red;
		uint8 green;
};

#endif
