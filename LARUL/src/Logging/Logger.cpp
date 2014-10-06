#include "Logger.h"

Logger * Logger :: Instance = NULL;

Logger * Logger :: GetInstance ()
{
	
	if ( Instance == NULL )
		Instance = new Logger ();
	
	return Instance;
	
};

Logger :: Logger ():
	PrintMutex ( true ),
	LevelMutex ( true ),
	PrintLevel ( kLogLevel_Message ),
	TerminationLevel ( kLogLevel_Error )
{
	
	
	
};

Logger :: ~Logger ()
{
	
	
	
};

void Logger :: SetPrintLevel ( LogLevel Level )
{
	
	LevelMutex.Lock ();
	
	PrintLevel = Level;
	
	LevelMutex.Unlock ();
	
};

void Logger :: SetTerminationLevel ( LogLevel Level )
{
	
	LevelMutex.Lock ();
	
	TerminationLevel = Level;
	
	LevelMutex.Unlock ();
	
};

void Logger :: Log ( LogLevel Level, const char * Format, ... )
{
	
	LevelMutex.Lock ();
	
	LogLevel PLevel = PrintLevel;
	LogLevel TLevel = TerminationLevel;
	
	LevelMutex.Unlock ();
	
	if ( Level <= PLevel )
	{
		
		PrintMutex.Lock ();
		
		if ( Level <= TLevel )
			printf ( "!*********!\nTERMINATION:\n!*********!\n==> " );
		
		if ( Level == kLogLevel_FatalError )
			printf ( "FATAL ERROR: " );
		
		else if ( Level == kLogLevel_Error )
			printf ( "ERROR: " );
		
		else if ( Level == kLogLevel_Warning )
			printf ( "WARNING: " );
			
		va_list ArgumentList;
		
		va_start ( ArgumentList, Format );
		vprintf ( Format, ArgumentList );
		va_end ( ArgumentList );
		
		printf ( "\n" );
		
		PrintMutex.Unlock ();
		
	}
	
	if ( Level <= TLevel )
	{
		
		Thread :: Terminate ( NULL );
		
	}
	
};

void Logger :: ForcedLog ( const char * Format, ... )
{
	
	PrintMutex.Lock ();
	
	va_list ArgumentList;
	
	va_start ( ArgumentList, Format );
	vprintf ( Format, ArgumentList );
	va_end ( ArgumentList );
	
	printf ( "\n" );
	
	PrintMutex.Unlock ();
	
};
