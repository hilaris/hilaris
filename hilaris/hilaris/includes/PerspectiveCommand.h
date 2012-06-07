#ifndef _PERSPECTIVE_COMMAND_H_
#define _PERSPECTIVE_COMMAND_H_

#include <stdlib.h>

#include "oscar.h"
#include "Camera.h"
#include "Command.h"

/**
 *  @brief Command to adjust perspective.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 */
class PerspectiveCommand : public Command
{
	public:
	
		/**
		 *  @brief A constructor. Will construct this Command.
		 *
		 *  @param camera Camera Pointer to adjust its perspective
		 */
		PerspectiveCommand(Camera* camera):camera(camera){}
		virtual void execute();
		virtual void setParams(std::string params);
	private:
		Camera* camera;
		enum Camera::Perspective perspective;

};

#endif
