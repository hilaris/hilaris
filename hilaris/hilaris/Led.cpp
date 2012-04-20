#include "Led.h"

Led::Led()
{
	// Set Color to green
	this->setColor(0, 255);
	
	// Turn on LED
	this->on();
}

Led::~Led() {}

bool Led::setColor(uint8 red, uint8 green)
{
	// This function will turn on the LED, therefore we just set
	// the two colors to the instance and call the function in 
	// the function Led::on().
	// return (OscGpioSetTestLedColor(red, green) == SUCCESS);
	
	this->red   = red;
	this->green = green;
	
	return true;
}

bool Led::on()
{
	return (OscGpioSetTestLedColor(this->red, this->green) == SUCCESS);
}

bool Led::on(uint8 red, uint8 green)
{
	this->setColor(red, green);
	
	return this->on();
}


bool Led::off()
{
	return (OscGpioSetTestLed(false) == SUCCESS);
}

bool Led::toggle()
{
	return (OscGpioToggleTestLed() == SUCCESS);
}
