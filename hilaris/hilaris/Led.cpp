#include "Led.h"

Led::Led()
{
	this->on();
}

bool Led::setColor(uint8 red, uint8 green)
{
	return (OscGpioSetTestLedColor(red, green) == SUCCESS);
}

bool Led::on()
{
	return (OscGpioSetTestLed(true) == SUCCESS);
}


bool Led::off()
{
	return (OscGpioSetTestLed(false) == SUCCESS);
}

bool Led::toggle()
{
	return (OscGpioToggleTestLed() == SUCCESS);
}
