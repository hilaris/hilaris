#include "CommandCollection.h"

std::map<std::string, Command*> CommandCollection::commands;

void CommandCollection::registerCommand(std::string name, Command* command)
{
	CommandCollection::commands[name] = command;
}

void CommandCollection::execute(std::string command)
{
	int pos;
	if((pos = command.find_first_of(":"))>0) //command with params
	{
		std::string c = command.substr(0, pos);
		std::string param = command.substr(pos+1, command.length()-pos);
		
		if(CommandCollection::commands.find(c) != CommandCollection::commands.end())
		{
			CommandCollection::commands[c]->setParams(param);
			CommandCollection::commands[c]->execute();
		}
		
	}
	else //command without params
	{
		if(CommandCollection::commands.find(command) != CommandCollection::commands.end())
		{
			CommandCollection::commands[command]->execute();
		}
	}
}
