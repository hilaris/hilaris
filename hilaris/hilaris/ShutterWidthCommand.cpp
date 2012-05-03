#include "ShutterWidthCommand.h"

void ShutterWidthCommand::execute()
{
	this->camera->setShutterWidth(this->shutterwidth);
}

void ShutterWidthCommand::setParams(std::string params)
{
	this->shutterwidth = atoi(params.c_str());
}
