#ifndef _HILARIS_H_
#define _HILARIS_H_

#include <stdio.h>
#include <string.h>

class Camera;
class Image;
class DeviceIO;

#include "oscar.h"
#include "Camera.h"
#include "Image.h"
#include "DeviceIO.h"

class Hilaris {
	public:
		Hilaris();
		void setFrameBufferSize(int size);
		void setConsoleLogLevel(const enum EnOscLogLevel level) const;
		void setFileLogLevel(const enum EnOscLogLevel level) const;
		
		/**
		 *  @brief Get a Camera instance.
		 *
		 *  @return camera Returns a camera object.
		 */
		Camera* getCamera();
		
		int getFrameBufferSize() const;
		bool loaded() const;
		
	private:
		int loadSuccess;
		int frameBufferSize;
		
		Camera* camera;
};

#endif 
