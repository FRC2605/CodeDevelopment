#include "Error.h"

Error :: Error ( std :: string Type, std :: string File, uint32_t Line ):
	Type ( Type ),
	File ( File ),
	Line ( Line )
{
};

Error :: Error ( const char * Type, const char * File, uint32_t Line ):
	Type ( Type ),
	File ( File ),
	Line ( Line )
{	
};

Error :: ~Error () {};

std :: string Error :: GetErrorType () const
{
	
	return static_cast <const std :: string> ( Type );
	
};

std :: string Error :: GetErrorString ()
{
	
	std :: stringstream Out ( File );
	Out << ", " << Line << ": " << Type;
	
	return Out.str ();
	
};
