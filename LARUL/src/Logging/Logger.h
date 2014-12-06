#ifndef SHS_2605_LOGGER_H
#define SHS_2605_LOGGER_H

#include <stdio.h>
#include <stdarg.h>

#include "../Util/LError.h"

#include "../Threading/Mutex.h"
#include "../Threading/Thread.h"

#define LOG_FATALERROR ( x, args ... ) Logger :: GetInstance () -> Log ( Logger :: kLogLevel_FatalError, x, args )

/*
* Logger is a singleton utility class for keeping synchronized stdout output as well as managing debug information.
* There are two user-set levels which determine: 1) At what level is a log printed to stdout 2) At what level should the log terminate the current thread
*/

class Logger
{
public:

	typedef enum
	{
		
		kLogLevel_FatalError = 0,
		kLogLevel_Error = 1,
		kLogLevel_Warning = 2,
		
		kLogLevel_Message = 3,
		
		kLogLevel_Debug_0 = 4,
		kLogLevel_Debug_1 = 5,
		kLogLevel_Debug_2 = 6,
		kLogLevel_Debug_3 = 7
		
	} LogLevel;

	// Get the singleton. NOTE: You should ALWAYS call this at least once before starting any other thread. This function is not thread safe otherwise.
	static Logger * GetInstance ();
	
	// Set the print level.
	void SetPrintLevel ( LogLevel Level );
	// Set the thread termination level.
	void SetTerminationLevel ( LogLevel Level );
	
	// Log something. (printf like format)
	void Log ( LogLevel Level, const char * Format, ... );
	// Force a log. Note that this will never terminate a thread so long as sync primitives don't fail.
	void ForcedLog ( const char * Format, ... );

private:

	Logger ();
	~Logger ();
	
	static Logger * Instance;
	
	Mutex PrintMutex;
	Mutex LevelMutex;
	
	LogLevel PrintLevel;
	LogLevel TerminationLevel;

};

#endif
