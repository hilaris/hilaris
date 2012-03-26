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


/**
 *  @mainpage
 *  
 *  @section hello Hello
 *  Introduction
 *
 *  @section foo Foo
 *  Meep
 *  @code
 *  printf("foo");
 *  @endcode
 */

/**
 *  @brief The Hilaris-Framework. Your entry point to the Camera.
 *
 *  @description This is the main class of the framework. It is the starting
 *   point and will setup most of the things automatically.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 */
class Hilaris {
	public:
		Hilaris();
		
		/**
		 *  @brief Set the number of frame buffers
		 *
		 *  @description This is necessary because of the missing Memory-Management-Unit
		 *   on the Blackfin-Processor. We decided to use a fixed number
		 *   of buffers to minimize the allocations on the heap. Otherwise
		 *   it could lead to memory fragmentation.
		 *
		 *  @param size The number of Buffers.
		 */
		void setFrameBufferSize(int size);
		
		/**
		 *  @brief Set the system-wide console output level
		 *
		 *  @param level A member of EnOscLogLevel
		 */
		void setConsoleLogLevel(const enum EnOscLogLevel level) const;
		
		/**
		 *  @brief Set the system-wide file output level
		 *
		 *  @param level A member of EnOscLogLevel
		 */
		void setFileLogLevel(const enum EnOscLogLevel level) const;
		
		/**
		 *  @brief Get a Camera instance.
		 *
		 *  @return Returns a camera object.
		 */
		Camera* getCamera();
		
		/**
		 *  @brief Get the number of Framebuffers
		 *
		 *  @return The number of Framebuffers
		 */
		bool getFrameBufferSize();
		
		/**
		 *  @brief Returns true if the Hilaris has successfully loaded, false otherwise
		 *
		 *  @return Has Hilaris successfully loaded?
		 */
		bool loaded();
		
	private:
		int loadSuccess;
		int frameBufferSize;
		
		Camera* camera = NULL;
};

#endif
