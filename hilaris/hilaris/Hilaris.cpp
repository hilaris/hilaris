#include "Hilaris.h"
#include "Camera.h"
#include "Image.h"

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
	
	this->load_success = err;
		
	OscLogSetConsoleLogLevel(DEBUG);
	OscLogSetFileLogLevel(DEBUG);
}

void setConsoleLogLevel(const enum EnOscLogLevel level) const
{
	OscLogSetConsoleLogLevel(level);
}

void setFileLogLevel(const enum EnOscLogLevel level) const
{
	OscLogSetFileLogLevel(level);
}

void setFrameBufferSize(int size)
{
	this->frameBufferSize = size;
}

int getFrameBufferSize() const
{
	return this->frameBufferSize;
}

bool Hilaris::loaded() const
{
	return this->loadSuccess == SUCCESS;
}

/**
 *  @brief Get a Camera instance.
 *
 *  @return camera Returns a camera object.
 */
Camera* Hilaris::getCamera()
{
	if(this->camera == NULL)
	{
		Camera* camera = new Camera();
		
		// set some camera settings to sane default values
		camera->presetRegisters();
		camera->setPerspective(OSC_CAM_PERSPECTIVE_180DEG_ROTATE);
		camera->setAreaOfInterest(0, 0, OSC_CAM_MAX_IMAGE_WIDTH, OSC_CAM_MAX_IMAGE_HEIGHT);
		
		this->camera = camera;
	}
	
	return this->camera;
}
