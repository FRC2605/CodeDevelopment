#include "LError.h"

LError :: LError ( std :: string Type, std :: string File, uint32_t Line ):
	Type ( Type ),
	File ( File ),
	Line ( Line )
{
};

LError :: LError ( const char * Type, const char * File, uint32_t Line ):
	Type ( Type ),
	File ( File ),
	Line ( Line )
{	
};

LError :: ~LError () {};

std :: string LError :: GetErrorType () const
{
	
	return static_cast <const std :: string> ( Type );
	
};

std :: string LError :: GetErrorString ()
{
	
	std :: stringstream Out ( File );
	Out << File << ", " << Line << ": " << Type;
	
	return Out.str ();
	
};
