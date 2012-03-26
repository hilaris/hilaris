#include "Camera.h"


Camera::Camera()  {}
Camera::~Camera() {}

/**
 *	@brief Set a manual exposure time.
 *
 *  @param width uint32 numerical representation of the shutter width.
 *               Sane values are between 100 and 1500.
 *
 */
void Camera::setShutterWidth(uint32 width)
{	
	OscCamSetShutterWidth(width);
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
void Camera::setBlackLevelOffset(uint16 offset)
{
	OscCamSetBlackLevelOffset(offset);
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
void Camera::setAutoExposure(bool enabled) {
	uint16 reg_val;
	OscCamGetRegisterValue(0xAF, &reg_val);
	OscCamSetRegisterValue(0xAF, (reg_val & ~0x1) | (uint16)enabled);
}

/**
 *  @brief Check wheter auto exposure is enabled or disabled on the camera.
 *
 *  @return enabled
 */
bool Camera::getAutoExposure() const {
	uint16 reg_val;
	OscCamGetRegisterValue(0xAF, &reg_val);
	return(reg_val & 0x1);
}

/**
 *  @brief A wrapper function for OscCamPresetRegs(). Will setup the camera with some sane values.
 *
 *  @description The following things will be performed on the camera:
 *     @li Reset frame capture and AGC/Exposure logic.
 *     @li Set snapshot mode, simultaneous readout.
 *     @li Mark image as colorfull, linear taken.
 *     @li Disable AGC/AEC.
 *     @li Set black level offset to 13.
 *     @li Set shutter width to 15000.
 *     @li Setup region of interest as full sized image.
 *     @li Setup a default perspective.
 */
void Camera::presetRegisters()
{
	OscCamPresetRegs();
}

/**
 *  Set the perspective of the image taken.
 *
 *  @param perspective A member of EnOscCamPerspective
 */
void Camera::setPerspective(enum EnOscCamPerspective p)
{
	OscCamSetupPerspective(p);
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
void Camera::setAreaOfInterest(uint16 lowX, uint16 lowY, uint16 width, uint16 height)
{

}

void Camera::createFrameBuffer()
{

}

void Camera::createMultiBuffer(int numOfBuf)
{

}

void Camera::removeBuffers()
{

}

Image* Camera::captureImage()
{
	return new Image();
}
