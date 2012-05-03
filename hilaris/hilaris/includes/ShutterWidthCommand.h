#ifndef _SHUTTERWIDTH_COMMAND_H_
#define _SHUTTERWIDTH_COMMAND_H_

#include <stdlib.h>

#include "oscar.h"
#include "Camera.h"
#include "Command.h"

class ShutterWidthCommand : public Command
{
	public:
		ShutterWidthCommand(Camera* camera):camera(camera){}
		virtual void execute();
		virtual void setParams(std::string params);
	private:
		Camera* camera;
		uint32 shutterwidth;

};

#endif
