#include "ShutterWidthCommand.h"

void ShutterWidthCommand::execute()
{
	if(this->autoExp)
	{
		this->camera->setAutoExposure(true);
	}
	else
	{
		this->camera->setAutoExposure(true);
		this->camera->setShutterWidth(this->shutterwidth);
	}	
}

void ShutterWidthCommand::setParams(std::string params)
{
	if(atoi(params.c_str())<0)
	{
		this->autoExp = true;
	}
	else
	{
		this->autoExp = false;
		this->shutterwidth = atoi(params.c_str());
	}
}
