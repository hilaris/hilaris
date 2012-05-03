#ifndef _COMMAND_H_
#define _COMMAND_H_

#include <string>

class Command
{
	public:
		virtual void execute() = 0;
		virtual void setParams(std::string params) = 0;
		virtual ~Command(){};
};

#endif
