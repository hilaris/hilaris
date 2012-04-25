#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <string.h>

#include "oscar.h"
#include "Debug.h"
#include "DrawableObject.h"
#include "Overlay.h"

enum ImageEncoding 
{
	BMP, JPG
};

/**
 *  @brief Base class for all Images.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 */
class Image {

	public:
	
		/**
		 *  @brief A constructor. Will create an Image at full size.
		 */
		Image();
		
		/**
		 *  @brief A constructor. Will create an Image with the specified width and height.
		 *
		 *  @param width  The width of this Image.
		 *  @param height The height of this Image.
		 */
		Image(uint16 width, uint16 height);
		
		// from http://www.gotw.ca/publications/mill18.htm
		// Guideline #4: A base class destructor should be either public and virtual, or protected and nonvirtual.
		virtual ~Image();
		
		/**
		 *  @brief Get an OSC_PICTURE, the representation of an Image in plain-old Oscar.
		 *  @return An OSC_PICTURE image struct.
		 */
		OSC_PICTURE& getOscarContext();
		
		/**
		 *  @brief Set up an internal representation of an OSC_PICTURE, the so
		 *   called OscarContext
		 *  @pre Call Image::setOscarContext first, in order to get a filled struct.
		 */
		void setOscarContext();
		
		/**
		 *  @bried Copies image data from specified pointer address into this Image
		 *  @param data Pointer to image data
		 */
		void copyData(uint8* data);
		
		/**
		 *  @brief Save this image.
		 *
		 *  @param path A path where to save this image.
		 *  @param enc The encoding which should be used. Currently only BMP is
		 *   supported.
		 *
		 *  @warning It is only possible to save BGRImages at this time. Therefore
		 *   a BinaryImage has to override this function in order to be storeable.
		 */
		virtual void save(const char* path, enum ImageEncoding enc = BMP);
		
		/**
		 *  @brief Draw a given Overlay to the Image.
		 *  @param overlay The overlay including the DrawableObjects.
		 */
		virtual void drawOverlay(Overlay* overlay);
		
		/**
		 *  @brief Get the width of the Image.
		 *  @return The image width.
		 */
		uint16 getWidth();
		
		/**
		 *  @brief Get the height of the Image.
		 *  @return The image height.
		 */
		uint16 getHeight();
		
		/**
		 *  @brief Return a pointer to the underlying image data. Has to be overwritten.
		 *  @return The data pointer.
		 */
		virtual uint8* getDataPtr() = 0;
		
		/**
		 *  @brief Get the image type. Has to be overwritten.
		 *  @return The image type.
		 */
		virtual EnOscPictureType getType() = 0;
		
		/**
		 *  @brief The maximum width of an image.
		 */
		static const int MAX_WIDTH = OSC_CAM_MAX_IMAGE_WIDTH;
		
		/**
		 *  @brief The maximum height of an image.
		 */
		static const int MAX_HEIGHT = OSC_CAM_MAX_IMAGE_HEIGHT;
		
		/**
		 *  @brief Save an Oscar Context to a given path
		 *
		 *  @param pic The OSC_PICTURE struct which contains the data.
		 *  @param path Where to save this image.
		 *  @see Image::save will call this function.
		 */
		void saveContext(struct OSC_PICTURE pic, const char* path);
		
	protected:
	
		/**
		 *  @brief The image width;
		 */
		uint16 width;
		
		/**
		 *  @brief The image height;
		 */
		uint16 height;
		
		/**
		 *  @brief The Image type.
		 */
		enum EnOscPictureType type;
		
		/**
		 *  @brief An OSC_PICTURE struct of this image.
		 *  @see Image::getOscarContext, Image::setOscarContext
		 */
		OSC_PICTURE oscarContext;
};

#endif 
