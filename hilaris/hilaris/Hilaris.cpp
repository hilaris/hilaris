#include "Hilaris.h"

Hilaris::Hilaris()
{
	this->camera = NULL;
	
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

void Hilaris::resetCamera()
{
	this->camera = NULL;
}

Camera* Hilaris::getCamera()
{
	if(this->camera == NULL)
	{
		this->camera = new Camera();
	}
	
	return this->camera;
}

Camera* Hilaris::getCamera(enum EnOscPictureType type)
{
	if(this->camera == NULL)
	{
		this->camera = new Camera(type);
	}
	
	return this->camera;
}

Camera* Hilaris::getCamera(uint8 bufferSize)
{
	if(this->camera == NULL)
	{
		this->camera = new Camera(bufferSize);
	}
	
	return this->camera;
}

Camera* Hilaris::getCamera(uint16 width, uint16 height)
{
	if(this->camera == NULL)
	{
		this->camera = new Camera(width, height);
	}
	
	return this->camera;
}

Camera* Hilaris::getCamera(uint16 lowX, uint16 lowY, uint16 width, uint16 height)
{
	if(this->camera == NULL)
	{
		this->camera = new Camera(lowX, lowY, width, height);
	}
	
	return this->camera;
}

Camera* Hilaris::getCamera(uint16 lowX, uint16 lowY, uint16 width, uint16 height, enum EnOscPictureType type)
{
	if(this->camera == NULL)
	{
		this->camera = new Camera(lowX, lowY, width, height, type);
	}
	
	return this->camera;
}

Camera* Hilaris::getCamera(uint16 lowX, uint16 lowY, uint16 width, uint16 height, enum EnOscPictureType type, uint8 bufferSize)
{
	if(this->camera == NULL)
	{
		this->camera = new Camera(lowX, lowY, width, height, type, bufferSize);
	}
	
	return this->camera;
}
