#ifndef _COMMAND_COLLECTION_H_
#define _COMMAND_COLLECTION_H_

#include <stdio.h>
#include <string>
#include <map>

#include "Command.h"

/**
 *  @brief CommandCollection to register and execute several Command.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 */
class CommandCollection
{
	public:
		/**
		 *  @brief Register a Command
		 *
		 *  @param name The name of the Command
		 *  @param command Command pointer
		 */
		static void registerCommand(std::string name, Command* command);
		
		/**
		 *  @brief Executes a Command if it is registered
		 *
		 *  @param command String representation of a command
		 */
		static void execute(std::string command);
	private:
		static std::map<std::string, Command*> commands;	
};

#endif
