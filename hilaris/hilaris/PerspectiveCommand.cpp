#include "PerspectiveCommand.h"

void PerspectiveCommand::execute()
{
	this->camera->setPerspective(this->perspective);
}

void PerspectiveCommand::setParams(std::string params)
{
	if(params=="default")
	{
		this->perspective = Camera::DEFAULT;
	}
	else if(params=="v_mirror")
	{
		this->perspective = Camera::VERTICAL_MIRROR;
	}
	else if(params=="h_mirror")
	{
		this->perspective = Camera::HORIZONTAL_MIRROR;
	}
	else if(params=="rotate")
	{
		this->perspective = Camera::ROTATE_180DEG;
	}
	else
	{
		this->perspective = Camera::ROTATE_180DEG;
	}
}
