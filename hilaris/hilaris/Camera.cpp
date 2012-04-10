#include "Camera.h"

Camera::~Camera() {}

Camera::Camera()
{
	this->init(0, 0, OSC_CAM_MAX_IMAGE_WIDTH, OSC_CAM_MAX_IMAGE_HEIGHT, new DebayerBGRFast(), 2);
}

Camera::Camera(Debayer* debayer)
{
	this->init(0, 0, OSC_CAM_MAX_IMAGE_WIDTH, OSC_CAM_MAX_IMAGE_HEIGHT, debayer, 2);
}

Camera::Camera(uint8 bufferSize)
{
	this->init(0, 0, OSC_CAM_MAX_IMAGE_WIDTH, OSC_CAM_MAX_IMAGE_HEIGHT, new DebayerBGRFast(), bufferSize);
}

Camera::Camera(uint16 width, uint16 height)
{
	this->init(
		(OSC_CAM_MAX_IMAGE_WIDTH / 2)  - (width / 2),
		(OSC_CAM_MAX_IMAGE_HEIGHT / 2) - (height / 2),
		width,
		height,
		new DebayerBGRFast(),
		2
	);
}

/**
 *  Set a Region of Interest.
 *
 *  The sensor on the camera will be advised to just capture the window you define
 *  here. This is able to increase the speed of capturing, leading to a top framerate
 *  which is higher than the 60fps you have while using a full sized region of interest.
 *
 *  @param lowX   The X-Coordinate of the lower left corner.
 *  @param lowY   The Y-Coordinate of the lower left corner.
 *  @param width  The width of the window.
 *  @param height The height of the window.
 */
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
	this->setPerspective(OSC_CAM_PERSPECTIVE_180DEG_ROTATE);
	
	if(((lowX + width) <= OSC_CAM_MAX_IMAGE_WIDTH) &&
		(lowY + height) <= OSC_CAM_MAX_IMAGE_HEIGHT)
	{
		this->aoi.width = width;
		this->aoi.height = height;
		this->aoi.posX = lowX;
		this->aoi.posY = lowY;
	
		this->lastError = OscCamSetAreaOfInterest(lowX, lowY, width, height);
		
		if(this->lastError != SUCCESS) return false;
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
		if(!this->createBuffers(bufferSize)) return false;
	}
	else
	{
		this->lastError = EINVALID_PARAMETER;
		
		return false;
	}
	
	// create an image
	this->image = debayer->getObject(width, height);
	this->rawImage = new RawImage(this->aoi.width, this->aoi.height);
	
	//initialize processors
	this->processor = NULL;
	
	// finished initializing
	this->initialized = true;
	
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

bool Camera::createBuffers(uint8 bufferSize)
{
	for(int i = 0; i < bufferSize; i++)
	{
		// create a new buffer
		uint8* buffer = new uint8[bufferSize * this->aoi.height * this->aoi.width];
		
		// setting frame buffer
		this->lastError = OscCamSetFrameBuffer(i, this->aoi.width * this->aoi.height, buffer, true);
		
		// error handling
		if(this->lastError != SUCCESS) return false;
	}
	
	// handle multiple buffers
	if(bufferSize > 1)
	{
		uint8* bufferIds = new uint8[bufferSize]; 
		
		// create an array of buffer ids
		for(int j = 0; j < bufferSize; j++)
		{
			bufferIds[j] = j;
		}
		
		// setting to oscar
		this->lastError = OscCamCreateMultiBuffer(bufferSize, bufferIds);
		
		// error handling
		if(this->lastError != SUCCESS) return false;
	}
	
	// store multi buffer information
	this->isMultiBuffered = bufferSize > 1;
	
	return true;
}

bool Camera::addFrameProcessor(FrameProcessor* proc)
{
	this->processor = proc;
	
	return true;
}

/**
 *	@brief Set a manual exposure time.
 *
 *  @param width uint32 numerical representation of the shutter width.
 *               Sane values are between 100 and 1500.
 *
 */
bool Camera::setShutterWidth(uint32 width)
{	
	return (this->lastError = OscCamSetShutterWidth(width)) != SUCCESS;
}

/**
 *	@brief Get the manual set exposure time.
 *  @return width Returns a unit32 numerical representation of the shutter width
                  which is set on the camera.
 */
uint32 Camera::getShutterWidth()
{
	uint32 width = 0;
	OscCamGetShutterWidth(&width);
	
	return width;
}

/**
 *  @brief Set a new black level offset.
 *
 *  @param offset uint16 numerical representation of the new offset which will
                  be set to the camera.
 */
bool Camera::setBlackLevelOffset(uint16 offset)
{
	return (this->lastError = OscCamSetBlackLevelOffset(offset)) != SUCCESS;
}

/**
 *  @brief Get the black level offset which will is set on the camera.
 *
 *  @return offset unit16 numerical representation of the offset.
 */
uint16 Camera::getBlackLevelOffset()
{
	uint16 offset = 0;
	OscCamGetBlackLevelOffset(&offset);
	
	return offset;
}

/**
 *  @brief Enable or disable auto exposure on the camera.
 *
 *  @param enabled Wheter you enable or disable auto exposure on the camera.
 */
bool Camera::setAutoExposure(bool enabled)
{
	uint16 reg_val;	
	OscCamGetRegisterValue(0xAF, &reg_val);
	return (this->lastError = OscCamSetRegisterValue(0xAF, (reg_val & ~0x1) | (uint16)enabled)) != SUCCESS;
}

/**
 *  @brief Check wheter auto exposure is enabled or disabled on the camera.
 *
 *  @return enabled
 */
bool Camera::getAutoExposure() const
{
	uint16 reg_val;
	OscCamGetRegisterValue(0xAF, &reg_val);
	return(reg_val & 0x1);
}

/**
 *  @brief A wrapper function for OscCamPresetRegs(). Will setup the camera with some sane values.
 *
 *  @description The following things will be performed on the camera:
 *   @li Reset frame capture and AGC/Exposure logic.
 *   @li Set snapshot mode, simultaneous readout.
 *   @li Mark image as colorfull, linear taken.
 *   @li Disable AGC/AEC.
 *   @li Set black level offset to 13.
 *   @li Set shutter width to 15000.
 *   @li Setup region of interest as full sized image.
 *   @li Setup a default perspective.
 */
bool Camera::presetRegisters()
{
	return (this->lastError = OscCamPresetRegs()) != SUCCESS;
}

/**
 *  Set the perspective of the image taken.
 *
 *  @param perspective A member of EnOscCamPerspective
 */
bool Camera::setPerspective(enum EnOscCamPerspective p)
{
	return (this->lastError = OscCamSetupPerspective(p)) != SUCCESS;
}

/**
 *  @todo max age and timeout implementation
 */
Image* Camera::captureImage()
{
	if(!this->initialized) return NULL;
	
	uint8* rawPic = NULL;
	int mb = this->isMultiBuffered ? OSC_CAM_MULTI_BUFFER : 0;
	
	if(OscCamSetupCapture(mb) == SUCCESS)
	{
		if(OscGpioTriggerImage() == SUCCESS)
		{
			if(OscCamReadPicture(mb, &rawPic, 0, 0) == SUCCESS)
			{
				OscLog(DEBUG, "Trying to copy rawdata to RawImage\n");
				memcpy(this->rawImage->getDataPtr(), rawPic, this->aoi.width * this->aoi.height);
				
				rawPic = this->image->getDataPtr();
				OscLog(DEBUG, "this->image %d %d %d\n", rawPic[10], rawPic[100], rawPic[1000]);
				
				this->debayer->debayer(this->rawImage, this->image);
				OscLog(DEBUG, "Debayered RawImage\n");
				
				if(this->processor != NULL)
				{
					this->processor->process(this->image);
				}
				
				return this->image;
			}
		}
	}
	
	return NULL;
}
