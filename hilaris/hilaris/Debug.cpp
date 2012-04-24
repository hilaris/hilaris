#include "Debug.h"

int Debug::BUFFER_MAX = 256;

void Debug::log(const char* strFormat, ...)
{
	// create dynamic argument list
	va_list ap;
	char buffer[Debug::BUFFER_MAX];

	va_start(ap, strFormat);
	vsprintf (buffer, strFormat, ap);
	
	// pass to osc log	
	OscLog((EnOscLogLevel)INFO, buffer);
	va_end(ap);
}

void Debug::log(enum Debug::Level level, const char* strFormat, ...)
{
	// create dynamic argument list
	va_list ap;
	char buffer[Debug::BUFFER_MAX];

	va_start(ap, strFormat);
	vsprintf (buffer, strFormat, ap);
	
	// pass to osc log
	OscLog(Debug::switchOscar(level), buffer);
	va_end(ap);
}

void Debug::fatal(const char * strFormat, ...)
{
	// create dynamic argument list
	va_list ap;
	char buffer[Debug::BUFFER_MAX];

	va_start(ap, strFormat);
	vsprintf (buffer, strFormat, ap);
	
	// pass to osc fatal
	OscFatalErr(strFormat, ap);
	va_end(ap);
}

EnOscLogLevel Debug::switchOscar(Debug::Level level)
{
	EnOscLogLevel oscarLevel;
	
	switch(level)
	{
		case NOLOG:
			oscarLevel = (EnOscLogLevel)NOLOG;
		break;
		
		case EMERGENCY:
			oscarLevel = (EnOscLogLevel)EMERG;
		break;
		
		case ALERT:
			oscarLevel = (EnOscLogLevel)ALERT;
		break;
		
		case CRITICAL:
			oscarLevel = (EnOscLogLevel)CRITICAL;
		break;
		
		case ERROR:
			oscarLevel = (EnOscLogLevel)ERROR;
		break;
		
		case WARNING:
			oscarLevel = (EnOscLogLevel)WARN;
		break;
		
		case NOTICE:
			oscarLevel = (EnOscLogLevel)NOTICE;
		break;
		
		case INFO:
			oscarLevel = (EnOscLogLevel)INFO;
		break;
		
		case DEBUG:
			oscarLevel = (EnOscLogLevel)DEBUG;
		break;
		
		case NONE:
			oscarLevel = (EnOscLogLevel)NONE;
		break;
		
		case SIMULATION:
			oscarLevel = (EnOscLogLevel)SIMULATION;
		break;
		
		default:
			oscarLevel = (EnOscLogLevel)DEBUG;	
	}
	
	return oscarLevel;
}
