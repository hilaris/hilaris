#include "Camera.h"

Camera::~Camera()
{
	// destroy buffers
	this->destroyBuffers();
	
	if(this->image    != NULL) delete this->image;
	if(this->rawImage != NULL) delete this->rawImage;
	if(this->debayer  != NULL) delete this->debayer;
	/*if(this->buffer   != NULL) */delete[] this->buffer;
	/*if(this->bufferIds!= NULL) */delete[] this->bufferIds;
}

Camera::Camera()
{
	this->init(0, 0, Image::MAX_WIDTH, Image::MAX_HEIGHT, new DebayerBGRFast(), 2);
}

Camera::Camera(Debayer* debayer)
{
	this->init(0, 0, Image::MAX_WIDTH, Image::MAX_HEIGHT, debayer, 2);
}

Camera::Camera(uint8 bufferSize)
{
	this->init(0, 0, Image::MAX_WIDTH, Image::MAX_HEIGHT, new DebayerBGRFast(), bufferSize);
}

Camera::Camera(uint16 width, uint16 height)
{
	this->init(
		(Image::MAX_WIDTH / 2)  - (width / 2),
		(Image::MAX_HEIGHT / 2) - (height / 2),
		width,
		height,
		new DebayerBGRFast(),
		2
	);
}

Camera::Camera(uint16 lowX, uint16 lowY, uint16 width, uint16 height)
{
	this->init(lowX, lowY, width, height, new DebayerBGRFast(), 2);
}

Camera::Camera(uint16 lowX, uint16 lowY, uint16 width, uint16 height, Debayer* debayer)
{
	this->init(lowX, lowY, width, height, debayer, 2);
}

Camera::Camera(uint16 lowX, uint16 lowY, uint16 width, uint16 height, Debayer* debayer, uint8 bufferSize)
{
	this->init(lowX, lowY, width, height, debayer, bufferSize);
}

bool Camera::init(uint16 lowX, uint16 lowY, uint16 width, uint16 height, Debayer* debayer, uint8 bufferSize)
{
	//printf("init cam width %d height %d\n", width, height);
	this->initialized = false;
	
	// setting sane default values
	this->presetRegisters();
	this->setPerspective(ROTATE_180DEG);
	
	if(((lowX + width) <= Image::MAX_WIDTH) &&
		(lowY + height) <= Image::MAX_HEIGHT)
	{
		this->aoi.width = width;
		this->aoi.height = height;
		this->aoi.posX = lowX;
		this->aoi.posY = lowY;
	
		this->lastError = OscCamSetAreaOfInterest(lowX, lowY, width, height);
		
		if(this->lastError != SUCCESS)
		{
			return false;
		}
	}
	else
	{
		this->lastError = EINVALID_PARAMETER;
		return false;
	}
	
	//set debayer strategy
	this->debayer = debayer;
	
	// set type
	this->type = debayer->getType();
	
	if(bufferSize > 0)
	{
		// creating buffers
		if(!this->createBuffers(bufferSize))
		{
			return false;
		}
	}
	else
	{
		this->lastError = EINVALID_PARAMETER;
		
		return false;
	}
	
	// do not track fps by default
	this->trackFPS = false;
	
	// create an image
	this->image = debayer->getObject(width, height);
	this->rawImage = new RawImage(this->aoi.width, this->aoi.height);
	
	//initialize processors
	this->processor = NULL;
		
	int mb = this->isMultiBuffered ? OSC_CAM_MULTI_BUFFER : 0;
	
	if(OscCamSetupCapture(mb) == SUCCESS)
	{
		usleep(10000);
		if(OscGpioTriggerImage() == SUCCESS)
		{
			usleep(10000);
			// finished initializing
			this->initialized = true;
		}
	}
	
	return true;
}

OSC_ERR Camera::getLastError()
{
	return this->lastError;
}

Debayer* Camera::getDebayer()
{
	return this->debayer;
}

uint16 Camera::getWidth()
{
	return this->aoi.width;
}

uint16 Camera::getHeight()
{
	return this->aoi.height;
}

uint16 Camera::getRegister(const uint32 reg)
{
	uint16 res;
	
	OscCamGetRegisterValue(reg, &res);
	
	return res;
}

bool Camera::setRegister(const uint32 reg, const uint16 value)
{
	return (OscCamSetRegisterValue(reg, value) == SUCCESS);
}

int Camera::getDebayeredImageSize()
{
	return this->image->getWidth() * this->image->getHeight() * (OSC_PICTURE_TYPE_COLOR_DEPTH(this->debayer->getType())/8);	
}

bool Camera::createBuffers(uint8 bufferSize)
{
	this->bufferSize = bufferSize;
	
	for(int i = 0; i < bufferSize; i++)
	{
		// create a new buffer
		this->buffer = new uint8[bufferSize * this->aoi.height * this->aoi.width];
		
		// setting frame buffer
		this->lastError = OscCamSetFrameBuffer(i, this->aoi.width * this->aoi.height, this->buffer, true);
		
		// error handling
		if(this->lastError != SUCCESS) return false;
	}
	
	// handle multiple buffers
	if(bufferSize > 1)
	{
		this->bufferIds = new uint8[bufferSize]; 
		
		// create an array of buffer ids
		for(int j = 0; j < bufferSize; j++)
		{
			this->bufferIds[j] = j;
		}
		
		// setting to oscar
		this->lastError = OscCamCreateMultiBuffer(bufferSize, this->bufferIds);
		
		// error handling
		if(this->lastError != SUCCESS) return false;
	}
	
	// store multi buffer information
	this->isMultiBuffered = bufferSize > 1;
	
	return true;
}

bool Camera::destroyBuffers()
{
	bool success = true;
	
	success = success && (OscCamDeleteMultiBuffer() == SUCCESS);
	
	// remove all buffers
	for(int i = 0; i < this->bufferSize; i++)
	{
		success = success && (OscCamSetFrameBuffer(i, 0, NULL, true) == SUCCESS);
	}
	
	return success;
}

bool Camera::addFrameProcessor(FrameProcessor* proc)
{
	this->processor = proc;
	
	return true;
}

bool Camera::setShutterWidth(uint32 width)
{
	this->lastError = OscCamSetShutterWidth(width);
	
	if(this->lastError == SUCCESS)
	{
		this->setAutoExposure(false);
		
		return true;
	}
	else
	{
		return false;
	}
}

uint32 Camera::getShutterWidth()
{
	uint32 width = 0;
	OscCamGetShutterWidth(&width);
	
	return width;
}

bool Camera::setBlackLevelOffset(uint16 offset)
{
	return (this->lastError = OscCamSetBlackLevelOffset(offset)) != SUCCESS;
}

uint16 Camera::getBlackLevelOffset()
{
	uint16 offset = 0;
	OscCamGetBlackLevelOffset(&offset);
	
	return offset;
}

bool Camera::setAutoExposure(bool enabled)
{
	uint16 reg_val;	
	OscCamGetRegisterValue(0xAF, &reg_val);
	return (this->lastError = OscCamSetRegisterValue(0xAF, (reg_val & ~0x1) | (uint16)enabled)) != SUCCESS;
}

bool Camera::getAutoExposure() const
{
	uint16 reg_val;
	OscCamGetRegisterValue(0xAF, &reg_val);
	return(reg_val & 0x1);
}

bool Camera::presetRegisters()
{
	return (this->lastError = OscCamPresetRegs()) != SUCCESS;
}

bool Camera::setPerspective(enum Camera::Perspective perspective)
{
	// setup oscar wrapper
	enum EnOscCamPerspective oscPerspective;
	
	switch(perspective)
	{
		case DEFAULT:
			oscPerspective = OSC_CAM_PERSPECTIVE_DEFAULT;
		break;
		
		case HORIZONTAL_MIRROR:
			oscPerspective = OSC_CAM_PERSPECTIVE_HORIZONTAL_MIRROR;
		break;
		
		case VERTICAL_MIRROR:
			oscPerspective = OSC_CAM_PERSPECTIVE_VERTICAL_MIRROR;
		break;
		
		case ROTATE_180DEG:
			oscPerspective = OSC_CAM_PERSPECTIVE_180DEG_ROTATE;
		break;
	}
	
	return (this->lastError = OscCamSetupPerspective(oscPerspective)) != SUCCESS;
}

Image* Camera::captureImage()
{
	if(!this->initialized) return NULL;
	
	uint8* rawPic = NULL;
	int mb = this->isMultiBuffered ? OSC_CAM_MULTI_BUFFER : 0;
	
	if(OscCamReadPicture(mb, &rawPic,0,0) == SUCCESS)
	{
		usleep(4000);
	
		if(OscCamSetupCapture(mb) != SUCCESS)
			printf("Failed to setup capture\n");
		if(OscGpioTriggerImage() != SUCCESS)
			printf("GPIO trigger image failed\n");
			
			
		memcpy(this->rawImage->getDataPtr(), rawPic, this->aoi.width * this->aoi.height);
		
		rawPic = this->rawImage->getDataPtr();
		
		if(this->debayer != NULL)
		{
			printf("Debayering rawdata\n");
			this->debayer->debayer(this->rawImage, this->image);
			printf("Got a debayered image\n");
		}
		
		if(this->processor != NULL)
		{
			printf("before process\n");
			this->processor->process(this->image);
			printf("after process\n");
		}
		
		return this->image;
	}
	
	return NULL;
}
