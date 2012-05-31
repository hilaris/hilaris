#include "Hilaris.h"

Hilaris::Hilaris()
{
	this->camera = NULL;
	this->setRemoveOnCleanup(true);
	
	// check wheter gpio-file exists
	// if not, create it and fill it with
	// a default text
	FILE *file;
	
	file = fopen("gpio_in.txt","w");
	
	fprintf(file,"%s\n%s", "!	Time	IN1	IN2", "@	0	0	0");
	fclose(file);
	
	OSC_ERR err;
		
	err = OscCreate(
	  &OscModule_log, 
	  &OscModule_sup, 
	  &OscModule_bmp, 
	  &OscModule_cam,  
	  &OscModule_vis,
	  &OscModule_gpio,
	  &OscModule_ipc,
	  &OscModule_dspl,
	  &OscModule_hsm,
	  &OscModule_cfg,
	  &OscModule_jpg,
	  &OscModule_sup,
	  &OscModule_frd,
	  &OscModule_dma
	);
	
	this->gpio = new IO();
	
	#if defined(OSC_HOST)
	
	void *hFileNameReader;
	
	OscFrdCreateConstantReader(&hFileNameReader, "test.bmp");
	OscCamSetFileNameReader(hFileNameReader);
	
	#endif
	
	this->loadSuccess = err;
		
	OscLogSetConsoleLogLevel(DEBUG);
	OscLogSetFileLogLevel(DEBUG);
}

Hilaris::~Hilaris()
{
	// cleanup
	if(this->camera != NULL) delete this->camera;
	if(this->gpio   != NULL) delete this->gpio;
	
	// remove some files
	if(this->removeOnCleanup)
	{
		remove("gpio_in.txt");
		remove("gpio_out.txt");
		remove("osc_log");
		remove("osc_simlog");
	}
	
	OscDestroy();
}

char* Hilaris::getOscarVersion()
{
	char* strVersion;
	
	OscGetVersionString(&strVersion);
	
	return strVersion;
}

void Hilaris::setRemoveOnCleanup(bool remove)
{
	this->removeOnCleanup = remove;
}

void Hilaris::setConsoleLogLevel(const enum Debug::Level level) const
{
	OscLogSetConsoleLogLevel(Debug::switchOscar(level));
}

void Hilaris::setFileLogLevel(const enum Debug::Level level) const
{
	OscLogSetFileLogLevel(Debug::switchOscar(level));
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

IO* Hilaris::io()
{
	return this->gpio;
}

void Hilaris::resetCamera()
{
	if(this->camera != NULL) delete this->camera;
	
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

Camera* Hilaris::getCamera(Debayer* debayer)
{
	if(this->camera == NULL)
	{
		this->camera = new Camera(debayer);
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

Camera* Hilaris::getCamera(uint16 lowX, uint16 lowY, uint16 width, uint16 height, Debayer* debayer)
{
	if(this->camera == NULL)
	{
		this->camera = new Camera(lowX, lowY, width, height, debayer);
	}
	
	return this->camera;
}

Camera* Hilaris::getCamera(uint16 lowX, uint16 lowY, uint16 width, uint16 height, Debayer* debayer, uint8 bufferSize)
{
	if(this->camera == NULL)
	{
		this->camera = new Camera(lowX, lowY, width, height, debayer, bufferSize);
	}
	
	return this->camera;
}
