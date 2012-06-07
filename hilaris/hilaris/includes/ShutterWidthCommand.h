#ifndef _SHUTTERWIDTH_COMMAND_H_
#define _SHUTTERWIDTH_COMMAND_H_

#include <stdlib.h>

#include "oscar.h"
#include "Camera.h"
#include "Command.h"

/**
 *  @brief Command to adjust shutter width.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 */
class ShutterWidthCommand : public Command
{
	public:
	
		/**
		 *  @brief A constructor. Will construct this Command.
		 *
		 *  @param camera Camera Pointer to adjust its shutter width
		 */
		ShutterWidthCommand(Camera* camera):camera(camera){}
		virtual void execute();
		virtual void setParams(std::string params);
	private:
		Camera* camera;
		uint32 shutterwidth;
		bool autoExp;

};

#endif
