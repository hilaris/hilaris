/*	Oscar, a hardware abstraction framework for the LeanXcam and IndXcam.
	Copyright (C) 2008 Supercomputing Systems AG
	
	This library is free software; you can redistribute it and/or modify it
	under the terms of the GNU Lesser General Public License as published by
	the Free Software Foundation; either version 2.1 of the License, or (at
	your option) any later version.
	
	This library is distributed in the hope that it will be useful, but
	WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser
	General Public License for more details.
	
	You should have received a copy of the GNU Lesser General Public License
	along with this library; if not, write to the Free Software Foundation,
	Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

/*! @file
 * @brief API definition for logging module
 * 
 */
#ifndef LOG_PUB_H_
#define LOG_PUB_H_

extern struct OscModule OscModule_log;

/*! Module-specific error codes.
 * These are enumerated with the offset
 * assigned to each module, so a distinction over
 * all modules can be made */
enum EnOscLogErrors {
	ELOG_INVALID_EXPOSURE_VALID = OSC_LOG_ERROR_OFFSET
};

/*! @brief The different log levels of the logging module */
enum EnOscLogLevel {
	NOLOG = -1, /* not allowed for OscLog() */
	EMERG,
	ALERT,
	CRITICAL,
	ERROR,
	WARN,
	NOTICE,
	INFO,
	DEBUG,
	NONE,
	/*! @brief A special loglevel used to report simulation results in the host implementation */
	SIMULATION = 255
};

/*=========================== API functions ============================*/

/*********************************************************************//*!
 * @brief Sets the highest log level to be output to the console
 * 
 * Set the log level to NONE to disable logging.
 * 
 * @param level The log level to set.
 *//*********************************************************************/
OSC_ERR OscLogSetConsoleLogLevel(const enum EnOscLogLevel level);

/*********************************************************************//*!
 * @brief Sets the highest log level to be output to the log file
 * 
 * Set the log level to NONE to disable logging.
 * 
 * @param level The log level to set.
 *//*********************************************************************/
OSC_ERR OscLogSetFileLogLevel(const enum EnOscLogLevel level);

/*********************************************************************//*!
 * @brief Logs a message.
 * 
 * The console and the log file have different log levels. This log level
 * is first checked before writing out a message.
 * 
 * @param level The log level of the message.
 * @param strFormat Format string of the message.
 * @param ... Format parameters of the message.
 *//*********************************************************************/
OSC_ERR OscLog(const enum EnOscLogLevel level, const char * strFormat, ...);

/*********************************************************************//*!
 * @brief Logs a fatal error and terminates program.
 * 
 * This is only for fatal errors where the program has to be stopped
 * 
 * @param strFormat Format string of the message.
 * @param ... Format parameters of the message.
 *//*********************************************************************/
OSC_ERR OscFatalErr(const char * strFormat, ...);


#endif /*LOG_PUB_H_*/
