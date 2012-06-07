#ifndef _COMMAND_H_
#define _COMMAND_H_

#include <string>

/**
 *  @brief Command Interface
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 */
class Command
{
	public:
	
		/**
		 *  @brief Executes this Command
		 */
		virtual void execute() = 0;
		
		/**
		 *  @brief Extracts parameters from the given String
		 *
		 *  @param params String with concatenated parameters
		 */
		virtual void setParams(std::string params) = 0;
		virtual ~Command(){};
};

#endif
