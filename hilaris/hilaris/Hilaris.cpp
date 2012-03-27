#include "Hilaris.h"

Hilaris::Hilaris()
{
	OSC_ERR err;
	
	err = OscCreate(
	  &OscModule_log, 
	  &OscModule_sup, 
	  &OscModule_bmp, 
	  &OscModule_cam,  
	  &OscModule_vis,
	  &OscModule_gpio
	);
	
	this->loadSuccess = err;
		
	OscLogSetConsoleLogLevel(DEBUG);
	OscLogSetFileLogLevel(DEBUG);
}

void Hilaris::setConsoleLogLevel(const enum EnOscLogLevel level) const
{
	OscLogSetConsoleLogLevel(level);
}

void Hilaris::setFileLogLevel(const enum EnOscLogLevel level) const
{
	OscLogSetFileLogLevel(level);
}

void Hilaris::setFrameBufferSize(int size)
{
	this->frameBufferSize = size;
}

int Hilaris::getFrameBufferSize() const
{
	return this->frameBufferSize;
}

bool Hilaris::loaded() const
{
	return this->loadSuccess == SUCCESS;
}

Camera* Hilaris::getCamera()
{
	if(this->camera == NULL)
	{
		Camera* camera = new Camera();
		
		this->camera = camera;
	}
	
	return this->camera;
}
