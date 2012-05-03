#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <vector>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <iostream>

#include "oscar.h"
#include "Debug.h"
#include "RawImage.h"
#include "Image.h"
#include "Debayer.h"
#include "FrameProcessor.h"
#include "DebayerBGRFast.h"

#define REG_AEC_AGC_ENABLE 0xaf
#define CAM_REG_RESERVED_0x20 0x20
#define CAM_REG_CHIP_CONTROL 0x07

/**
 *  @brief Area of Interest structure.
 */
struct AreaOfInterest
{
	/**
	 *  @brief The X-Coordinate of the lower corner of the window.
	 */
	uint16 posX;
	
	/**
	 *  @brief The Y-Coordinate of the lower corner of the window.
	 */
	uint16 posY;
	
	/**
	 *  @brief The width of the resulting image.
	 */
	uint16 width;
	
	/**
	 *  @brief The height of the resulting image.
	 */
	uint16 height;
};

/**
 *  @brief A represantation of the leanXCam
 *
 *  This is the camera class. It is wrapped around the corresponding Oscar functions.
 *  While setup it will asure that sane configuration values are set to the camera.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 *
 *  @warning While Hilarious is creating Camera the first time, it will call the
 *           Oscar-internal function presetRegister. It is possible that you have
 *           to reset some stuff which is made there.
 */
class Camera {
	friend class Hilaris;
	
	public:
	
		/**
		 *  @brief Get a Camera instance.
		 *
		 *  @return Returns a camera object.
		 */
		Camera();
		
		/**
		 *  @brief Get a Camera instance by specifing a Debayer.
		 *  
		 *  @param debayer A debayer instance
		 *  @return Returns a camera object.
		 */
		Camera(Debayer* debayer);
		
		/**
		 *  @brief Get a Camera instance by specifing a buffer size.
		 *  
		 *  @param bufferSize How many buffers should be used on the camera.
		 *  @return Returns a camera object.
		 */
		Camera(uint8 bufferSize);
		
		/**
		 *  @brief Get a Camera instance by specifing the image size.
		 *
		 *  The resulting image is a centered cut out of the original full sized image.
		 *  
		 *  @note The sensor on the camera will be advised to just capture the window you define
		 *   here. This is able to increase the speed of capturing, leading to a top framerate
		 *   which is higher than the 60fps you have while using a full sized region of interest.
		 *
		 *  @param width  The image width.
		 *  @param height The image height.
		 *
		 *  @return Returns a camera object.
		 */
		Camera(uint16 width, uint16 height);
		
		/**
		 *  @brief Get a Camera instance by specifing a full Area of Interest.
		 *
		 *  @note The sensor on the camera will be advised to just capture the window you define
		 *   here. This is able to increase the speed of capturing, leading to a top framerate
		 *   which is higher than the 60fps you have while using a full sized region of interest.
		 *
		 *  @param lowX   The X-Coordinate of the lower corner
		 *  @param lowY   The Y-Coordinate of the lower corner.
		 *  @param width  The image width.
		 *  @param height The image height.
		 *
		 *  @return Returns a camera object.
		 */
		Camera(uint16 lowX, uint16 lowY, uint16 width, uint16 height);
		
		/**
		 *  @brief Get a Camera instance by specifing a full Area of Interest and a Debayer
		 *
		 *  @note The sensor on the camera will be advised to just capture the window you define
		 *   here. This is able to increase the speed of capturing, leading to a top framerate
		 *   which is higher than the 60fps you have while using a full sized region of interest.
		 *
		 *  @param lowX    The X-Coordinate of the lower corner
		 *  @param lowY    The Y-Coordinate of the lower corner.
		 *  @param width   The image width.
		 *  @param height  The image height.
		 *  @param debayer A Debayer instance.
		 *
		 *  @return Returns a camera object.
		 */
		Camera(uint16 lowX, uint16 lowY, uint16 width, uint16 height, Debayer* debayer);
		
		/**
		 *  @brief Get a Camera instance by specifing a full Area of Interest, a Debayer and the buffer size.
		 *
		 *  @note The sensor on the camera will be advised to just capture the window you define
		 *   here. This is able to increase the speed of capturing, leading to a top framerate
		 *   which is higher than the 60fps you have while using a full sized region of interest.
		 *
		 *  @param lowX    The X-Coordinate of the lower corner
		 *  @param lowY    The Y-Coordinate of the lower corner.
		 *  @param width   The image width.
		 *  @param height  The image height.
		 *  @param debayer A Debayer instance.
		 *  @param bufferSize The buffer size the Camera should use.
		 *
		 *  @return Returns a camera object.
		 */
		Camera(uint16 lowX, uint16 lowY, uint16 width, uint16 height, Debayer* debayer, uint8 bufferSize);
		
		~Camera();
		
		/** The Image alignment. */
		enum Perspective
		{
			/** The default perspective. No rotation or mirroring. */
			DEFAULT,
			
			/** Mirror the Image horizontal */
			HORIZONTAL_MIRROR,
			
			/** Mirror the Image verticaly */
			VERTICAL_MIRROR,
			
			/** Rotate the Image by 180°. This will fit most of the purposes and is therefore the interal Hilaris standard. */
			ROTATE_180DEG
		};
		
		/**
		 *  @brief A wrapper function for OscCamPresetRegs(). Will setup the camera with some sane values.
		 *
		 *  The following things will be performed on the camera:
		 *   @li Reset frame capture and AGC/Exposure logic.
		 *   @li Set snapshot mode, simultaneous readout.
		 *   @li Mark image as colorfull, linear taken.
		 *   @li Disable AGC/AEC.
		 *   @li Set black level offset to 13.
		 *   @li Set shutter width to 15000.
		 *   @li Setup region of interest as full sized image.
		 *   @li Setup a default perspective.
		 */
		bool presetRegisters();
		
		/**
		 *  @brief Capture an Image.
		 *
		 *  This function will capture a RawImage and debayer it with the given
		 *  Debayer. The returned Image is of the type the Debayer provides.
		 *
		 *  @return A pointer to the debayered Image.
		 *
		 *  @see Camera::Camera
		 *  @todo max age and timeout implementation
		 */
		Image* captureImage();
		
		/**
		 *  @brief Get the current exposer mode.
		 *  @return True if mode is set to auto, false otherwise.
		 */
		bool getAutoExposure() const;
		
		/**
		 *  @brief Retrieve the black level offset.
		 *  @return The black level offset.
		 */
		uint16  getBlackLevelOffset();
		
		/**
		 *  @brief Get the last error which occured while setting up and capturing
		 *   images.
		 *
		 *  @note By checking wheter this value is equal to SUCCESS, you can determine
		 *   if everything went correct.
		 *
		 *  @return The last error.
		 */
		OSC_ERR getLastError();
		
		/**
		 *  @brief Retrive the current shutter width.
		 *  @return The current shutter width.
		 */
		uint32  getShutterWidth();
		
		/**
		 *  @brief Get the image width.
		 *  @return The width of the image.
		 */
		uint16 getWidth();
		
		/**
		 *  @brief Get the image height.
		 *  @return The height of the image.
		 */
		uint16 getHeight();
		
		/**
		 *  @brief Get the size of debayered image data
		 *  @return size of debayered image data
		 */
		int getDebayeredImageSize();
		
		/**
		 *  @brief Let the exposure time to be set automatically or manual.
		 *  @param enabled True if auto, false if manual.
		 *
		 *  @return Success status.
		 */
		bool setAutoExposure(bool enabled);
		
		/**
		 *  @brief Set the black level offset to the given value
		 *  
		 *  @param offset The black level offset.
		 *  @return Success status.
		 */
		bool setBlackLevelOffset(uint16 offset);
		
		/**
		 *  @brief Set the perspective of the catpured Image.
		 *
		 *  Use this function to turn the image to your personal perspective.
		 *  For example turn it 180°.
		 *
		 *  @param perspective The perspective.
		 *  @return Success status.
		 */
		bool setPerspective(enum Camera::Perspective perspective);
		
		/**
		 *	@brief Set a manual exposure time.
		 *
		 *  @param width Numerical representation of the shutter width. Sane values are between 100 and 1500.
		 *  @return Success status.
		 */
		bool setShutterWidth(uint32 width);
		
		/**
		 *  @brief Add an instance of a FrameProcessor.
		 *
		 *  @param proc A pointer to address of the FrameProcessor
		 *  @return Success status.
		 */		
		bool addFrameProcessor(FrameProcessor* proc);
		
		/**
		 *  @brief Remove a FrameProcessor by the pointer to its address.
		 *
		 *  @param fpPtr A pointer to the address of the FrameProcessor.
		 *  @return Success status.
		 */		
		bool removeFrameProcessor(FrameProcessor* fpPtr);
		
		/**
		 *  @brief Get the Debayer which will be used to debayer the RawImage.
		 *  @return A pointer to the Debayer.
		 */
		Debayer* getDebayer();
		
		/**
		 *  @brief Get the value of a register on the Camera.
		 *  @return reg An uint32 representation of the register.
		 */
		uint16 getRegister(const uint32 reg);
		
		/**
		 *  @brief Set a register on the Camera.
		 *  @return Success status.
		 */
		bool setRegister(const uint32 reg, const uint16 value);

	private:
		enum EnOscPictureType type;
		struct AreaOfInterest aoi;
		OSC_ERR lastError;
		bool initialized;
		bool isMultiBuffered;
		bool trackFPS;
		Image* image;
		RawImage* rawImage;
		Debayer* debayer;
		std::vector<FrameProcessor*> fp;
		uint8 bufferSize;
		uint8* buffer;
		uint8* bufferIds;
		
		bool destroyBuffers();
		bool createBuffers(uint8 bufferSize);
		bool init(uint16 lowX, uint16 lowY, uint16 width, uint16 height, Debayer* debayer, uint8 bufferSize);
};

#endif 
