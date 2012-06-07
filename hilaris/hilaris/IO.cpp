#include "IO.h"

IO::IO()
{
	this->testLed = new Led();
}

IO::~IO()
{
	if(this->testLed != NULL)
	{
		delete this->testLed;
	}
}

bool IO::write(enum IO::Pin pin, bool active)
{
	return (OscGpioWrite(this->getOscarIO(pin), active) == SUCCESS);
}

bool IO::read(enum IO::Pin pin)
{
	bool active;
	
	OscGpioRead(this->getOscarIO(pin), &active);
	
	return active;
}

bool IO::setPolarity(enum IO::Pin pin, bool lowActive)
{
	return (OscGpioSetupPolarity(this->getOscarIO(pin), lowActive) == SUCCESS);
}
		
Led* IO::led()
{
	return this->testLed;
}

enum EnGpios IO::getOscarIO(enum IO::Pin pin)
{
	enum EnGpios oscarIO;
	
	switch(pin)
	{
		case IN1:
			oscarIO = GPIO_IN1;
		break;
		
		case IN2:
			oscarIO = GPIO_IN2;
		break;
		
		case OUT1:
			oscarIO = GPIO_OUT1;
		break;
		
		case OUT2:
			oscarIO = GPIO_OUT2;
		break;
		
		default:
			oscarIO = GPIO_OUT1;			
	}
	
	return oscarIO;
}
