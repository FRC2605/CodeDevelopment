#ifndef SHS_2605_LOGGER_H
#define SHS_2605_LOGGER_H

#include <stdio.h>
#include <stdarg.h>

#include "../Util/Error.h"

#include "../Threading/Mutex.h"
#include "../Threading/Thread.h"

#define LOG_FATALERROR ( x )

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

	static Logger * GetInstance ();
	
	void SetPrintLevel ( LogLevel Level );
	void SetTerminationLevel ( LogLevel Level );
	
	void Log ( LogLevel Level, const char * Format, ... );
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
