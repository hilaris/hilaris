#include "Debug.h"

void Debug::log(const char * strFormat, ...)
{
	// create dynamic argument list
	va_list ap;

	va_start(ap, strFormat);
	OscLog((EnOscLogLevel)DEBUG, strFormat, ap);
	va_end(ap);
}

void Debug::log(enum Debug::Level level, const char * strFormat, ...)
{
	// create dynamic argument list
	va_list ap;

	va_start(ap, strFormat);
	OscLog(Debug::switchOscar(level), strFormat, ap);
	va_end(ap);
}

void Debug::fatal(const char * strFormat, ...)
{
	// create dynamic argument list
	va_list ap;

	va_start(ap, strFormat);
	OscFatalErr(strFormat, ap);
	va_end(ap);
}

void Debug::start()
{
	OscSupWdtInit();
	
	Debug::frameClockLast = 0;
	Debug::frameClockCurrent = 0;
}

void Debug::end()
{
	OscSupWdtClose();
}

uint32 Debug::fps()
{
	if(Debug::frameClockLast > 0)
	{
		return OscSupCycToSecs(Debug::frameClockCurrent - Debug::frameClockLast);
	}
	else
	{
		return 0;
	}
}

void Debug::tick()
{
	OscSupWdtKeepAlive();
	
	Debug::frameClockLast = Debug::frameClockCurrent;
	Debug::frameClockCurrent = OscSupCycGet();
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
