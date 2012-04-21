#ifndef _HILARIS_H_
#define _HILARIS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// include oscar
#include "oscar.h"

// include images
#include "Image.h"
#include "RawImage.h"
#include "BGRImage.h"
#include "RGBImage.h"
#include "GreyscaleImage.h"
#include "BinaryImage.h"
#include "YUV422Image.h"

// include factories
#include "BinaryImageFactory.h"
#include "BGRImageFactory.h"
#include "GreyscaleImageFactory.h"
#include "RGBImageFactory.h"
#include "YUV422ImageFactory.h"

// include debayer
#include "Debayer.h"
#include "DebayerBinaryDirect.h"
#include "DebayerBGRFast.h"
#include "DebayerBGRStandard.h"
#include "DebayerBGRHalfsize.h"
#include "DebayerBGRBilinear.h"
#include "DebayerRGBStandard.h"
#include "DebayerGreyscaleFast.h"
#include "DebayerGreyscaleHalfsize.h"
#include "DebayerGreyscaleVector.h"
#include "DebayerYUV422Fast.h"

// include system classes
#include "Debug.h"
#include "Camera.h"
#include "FrameProcessor.h"
#include "StreamClient.h"
#include "StreamServer.h"
#include "Led.h"
#include "IO.h"

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
 *  This is the main class of the framework. It is the starting
 *   point and will setup most of the things automatically.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 *
 *  @include createHilaris.cpp
 */
class Hilaris {
	public:
		
		Hilaris();
		~Hilaris();
		
		/**
		 *  @brief Set the number of frame buffers
		 *
		 *  This is necessary because of the missing Memory-Management-Unit
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
		 *  @brief Get a Camera instance by specifing a Debayer.
		 *  
		 *  @param debayer A debayer instance
		 *  @return Returns a camera object.
		 */
		Camera* getCamera(Debayer* debayer);
		
		/**
		 *  @brief Get a Camera instance by specifing a buffer size.
		 *  
		 *  @param bufferSize How many buffers should be used on the camera.
		 *  @return Returns a camera object.
		 *
		 *  @include getCameraByDebayer.cpp
		 */
		Camera* getCamera(uint8 bufferSize);
		
		/**
		 *  @brief Get a Camera instance by specifing the image size.
		 *
		 *  The resulting image is a centered cut out of the original full sized image.
		 *
		 *  @param width  The image width.
		 *  @param height The image height.
		 *
		 *  @return Returns a camera object.
		 *
		 *  @include getCameraByBufferSize.cpp
		 */
		Camera* getCamera(uint16 width, uint16 height);
		
		/**
		 *  @brief Get a Camera instance by specifing a full Area of Interest.
		 *
		 *  @param lowX   The X-Coordinate of the lower corner
		 *  @param lowY   The Y-Coordinate of the lower corner.
		 *  @param width  The image width.
		 *  @param height The image height.
		 *
		 *  @return Returns a camera object.
		 */
		Camera* getCamera(uint16 lowX, uint16 lowY, uint16 width, uint16 height);
		
		/**
		 *  @brief Get a Camera instance by specifing a full Area of Interest and a Debayer
		 *
		 *  @param lowX    The X-Coordinate of the lower corner
		 *  @param lowY    The Y-Coordinate of the lower corner.
		 *  @param width   The image width.
		 *  @param height  The image height.
		 *  @param debayer A Debayer instance.
		 *
		 *  @return Returns a camera object.
		 */
		Camera* getCamera(uint16 lowX, uint16 lowY, uint16 width, uint16 height, Debayer* debayer);
		
		/**
		 *  @brief Get a Camera instance by specifing a full Area of Interest, a Debayer and the buffer size.
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
		Camera* getCamera(uint16 lowX, uint16 lowY, uint16 width, uint16 height, Debayer* debayer, uint8 bufferSize);
		
		/**
		 *  @brief Resets the Camera.
		 */
		void resetCamera();
		
		/**
		 *  @brief Get the number of Framebuffers
		 *
		 *  @return The number of Framebuffers
		 */
		int getFrameBufferSize() const;
		
		/**
		 *  @brief Returns true if the Hilaris has successfully loaded, false otherwise
		 *
		 *  @return Has Hilaris successfully loaded?
		 */
		bool loaded() const;
		
		/**
		 *  @brief Cleanup after Hilaris has been deconstructed.
		 *
		 *  Oscar creates a bunch of files, like logs, gpio-input and ouput files and so on.
		 *  Hilaris is able to get rid of this files, if you don't need them, so you always
		 *  have a clean and tidy.
		 */
		void setRemoveOnCleanup(bool remove);
		
		// usage: *this->getOscarVersion();
		char* getOscarVersion();
		
		IO* io();
		
	private:
		int loadSuccess;
		int frameBufferSize;
		bool removeOnCleanup;
		
		Camera* camera;
		IO* gpio;
};

#endif
