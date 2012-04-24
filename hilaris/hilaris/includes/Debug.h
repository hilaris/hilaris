#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <cstdarg>
#include "oscar.h"

class Debug
{
	friend class Hilaris;
	friend class Camera;
	
	public:
		
		/**
		 *  The Hilaris internal log level representations.
		 */
		enum Level
		{
			/** This is not supported by Oscar, don't use it. */
			NOLOG = -1,
			
			/** Highest log level. Extremly critical error. */
			EMERGENCY,
			
			/** One of the severest errors occured. */
			ALERT,
			
			/** A critical error occured. */
			CRITICAL,
			
			/** An error occured. */
			ERROR,
			
			/** Low severity, but just to be warned. */
			WARNING,
			
			/** A notice occured. */
			NOTICE,
			
			/** For your information. This is the standard log level if you don't pass one to Debug::log() */
			INFO,
			
			/** Just a message about what is going on. */
			DEBUG,
			
			/** Do not show this message. Simular to: don't log it. */
			NONE,
			
			/** A special log level for simulation only. Don't use it. */
			SIMULATION = 255
		};
		
		/**
		 *  @brief Log something to a file and console, depending on the given log
		     level.
		    
		    @param strFormat The format string, followed by the corresponding values.
		    @note Using this function, the log level passed to Oscar will be INFO.
		    @see Hilaris::setFileLogLevel and Hilaris::setConsoleLogLevel for details
		     on how to set the log level.
		 */
		static void log(const char * strFormat, ...);
		
		/**
		 *  @brief Log something to a file and console, depending on the given log
		     level.
		    
		    @param level The log level.
		    @param strFormat The format string, followed by the corresponding values.
		    @see Hilaris::setFileLogLevel and Hilaris::setConsoleLogLevel for details
		     on how to set the log level.
		 */
		static void log(enum Debug::Level level, const char * strFormat, ...);
		
		/**
		 *  @brief Log a fatal error.
		 *
		 *  @param strFormat The format string, followed by the corresponding values.
		 *  @warning This will shut down the application after executing this function.
		 */
		static void fatal(const char * strFormat, ...);
		
		static int BUFFER_MAX;
		
	private:
		static EnOscLogLevel switchOscar(Debug::Level level);
};

#endif
