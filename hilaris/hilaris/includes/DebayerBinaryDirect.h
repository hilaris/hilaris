#ifndef _DEBAYERBINARYDIRECT_H_
#define _DEBAYERBINARYDIRECT_H_

#include <string.h>

#include "oscar.h"
#include "Image.h"
#include "RawImage.h"
#include "BinaryImage.h"
#include "Debayer.h"

/**
 *  @brief Direct Debayer for BinaryImage.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 */
class DebayerBinaryDirect : public Debayer
{
	public:
	
		/**
		 *  @brief Get the image type. The return value is part of the EnOscPictureType enum.
		 *  @return Returns the type of the debayered Image.
		 */
		enum EnOscPictureType getType();
		
		/**
		 *  @brief Get an image pointer.
		 *  @return A pointer to a BGRImage.
		 */
		BinaryImage* getObject(uint16 width, uint16 height);
		
		/**
		 *  @brief This is where the action takes place. Debayer the image according
		 *   to the given image pointer, the raw image pointer and the underlying
		 *   Debayer.
		 *
		 *  @return Success status.
		 */
		bool debayer(RawImage* raw, Image* image);
		
		/**
		 *  @brief Get the size of the resulting Image.
		 *  @return Image size.
		 */
		long unsigned int getSize();
		
		/**
		 *  @brief Create a Debayer instance.
		 *
		 *  @param threshold The threshold used for debayering image.
		 *  @param blackIsForeground Is black or white the foreground.
		 */
		DebayerBinaryDirect(uint8 threshold = 127, bool blackIsForeground = false):threshold(threshold), blackIsForeground(blackIsForeground){}
		virtual ~DebayerBinaryDirect() {};
		
		/**
		 *  @brief Set threshold value.
		 *  @param value The threshold value. Between 0 and 255.
		 */
		void setThreshold(uint8 value);
		
		/**
		 *  @brief Define de back- and foreground color.
		 *  @param value True for black as foreground, false otherwise.
		 */
		void setBlackIsForeground(bool value);
		
		/**
		 *  @brief Get the threshold value.
		 *  @return The threshold value.
		 */
		uint8 getThreshold();
		
		/**
		 *  @brief Get the foreground color.
		 *  @return True if black is foreground color, false otherwise.
		 */
		bool getBlackIsForeground();
		
	private:
		uint8 threshold;
		bool blackIsForeground;
};

#endif
