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
		~Camera();
		
		void presetRegisters();
		void createFrameBuffer();
		void createMultiBuffer(int numOfBuf = 2);
		
		Image* captureImage();
		
		bool   getAutoExposure() const;
		uint16 getBlackLevelOffset();
		uint32 getShutterWidth();
		
		void setAreaOfInterest(uint16 lowX, uint16 lowY, uint16 width, uint16 height);
		void setAutoExposure(bool enabled);
		void setBlackLevelOffset(uint16 offset);
		void setMultipleBuffer(uint32 num);
		void setPerspective(enum EnOscCamPerspective p);
		void setShutterWidth(uint32 width);

	private:
		Camera();
		
		std::vector<uint8*> buffers;
		struct AreaOfInterest aoi;
		
		void removeBuffers();
};

#endif 
