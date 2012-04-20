#ifndef _IO_H_
#define _IO_H_

#include "oscar.h"
#include "Led.h"

class IO
{
	public:
		
		// @todo Leanxradio
		enum Pin
		{
			IN1 = 4,
			IN2 = 7,
			OUT1 = 2,
			OUT2 = 6
		};
		
		IO();
		~IO();
		
		bool write(enum IO::Pin pin, bool active);
		bool read(enum IO::Pin pin);
		bool setPolarity(enum IO::Pin pin, bool lowActive);
		
		Led* led();
	
	private:
		enum EnGpios getOscarIO(enum IO::Pin pin);
		
		Led* testLed;
};

#endif
