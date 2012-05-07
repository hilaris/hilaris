#ifndef _PERSPECTIVE_COMMAND_H_
#define _PERSPECTIVE_COMMAND_H_

#include <stdlib.h>

#include "oscar.h"
#include "Camera.h"
#include "Command.h"

class PerspectiveCommand : public Command
{
	public:
		PerspectiveCommand(Camera* camera):camera(camera){}
		virtual void execute();
		virtual void setParams(std::string params);
	private:
		Camera* camera;
		enum Camera::Perspective perspective;

};

#endif
