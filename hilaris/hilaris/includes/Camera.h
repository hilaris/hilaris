#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Hilaris.h"

#include <vector>
#include <stdio.h>

struct AreaOfInterest {
	uint16 posX;
	uint16 posY;
	uint16 width;
	uint16 height;
};

/**
 *  @brief A represantation of the leanXCam
 *
 *  @description This is the camera class. It is wrapped around the corresponding Oscar functions.
 *               While setup it will asure that sane configuration values are set to the camera.
 * *
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
		Camera();
		Camera(enum EnOscPictureType type);
		Camera(uint8 bufferSize);
		Camera(uint16 width, uint16 height);
		Camera(uint16 lowX, uint16 lowY, uint16 width, uint16 height);
		Camera(uint16 lowX, uint16 lowY, uint16 width, uint16 height, enum EnOscPictureType type);
		Camera(uint16 lowX, uint16 lowY, uint16 width, uint16 height, enum EnOscPictureType type, uint8 bufferSize);
		
		~Camera();
		
		bool presetRegisters();
		
		Image* captureImage();
		
		bool    getAutoExposure() const;
		uint16  getBlackLevelOffset();
		OSC_ERR getLastError();
		uint32  getShutterWidth();
		
		bool setAutoExposure(bool enabled);
		bool setBlackLevelOffset(uint16 offset);
		bool setPerspective(enum EnOscCamPerspective p);
		bool setShutterWidth(uint32 width);

	private:
	
		enum EnOscPictureType type;
		struct AreaOfInterest aoi;
		OSC_ERR lastError;
		bool initialized;
		bool isMultiBuffered;
		Image* image;
		
		bool createBuffers(uint8 bufferSize);
		bool init(uint16 lowX, uint16 lowY, uint16 width, uint16 height, enum EnOscPictureType type, uint8 bufferSize);
};

#endif 
