#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <cstdarg>
#include "oscar.h"

class Debug
{
	public:
		
		enum Level
		{
			NOLOG = -1,
			EMERGENCY,
			ALERT,
			CRITICAL,
			ERROR,
			WARNING,
			NOTICE,
			INFO,
			DEBUG,
			NONE,
			SIMULATION = 255
		};
		
		static void log(const char * strFormat, ...);
		static void log(enum Debug::Level level, const char * strFormat, ...);
		
		static void fatal(const char * strFormat, ...);
		
		static void start();
		static void end();
		static void tick();
		
	private:
		
		static EnOscLogLevel switchOscar(Debug::Level level);
};

#endif
