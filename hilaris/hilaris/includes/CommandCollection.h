#ifndef _COMMAND_COLLECTION_H_
#define _COMMAND_COLLECTION_H_

#include <stdio.h>
#include <string>
#include <map>

#include "Command.h"

class CommandCollection
{
	public:
		static void registerCommand(std::string name, Command* command);
		static void execute(std::string command);
	private:
		static std::map<std::string, Command*> commands;	
};

#endif
