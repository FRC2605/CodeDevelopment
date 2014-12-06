#ifndef LARUL_ERROR_H
#define LARUL_ERROR_H

#define THROW_ERROR(x) throw LError ( x, __FILE__, __LINE__ )

#include <string>
#include <sstream>
#include <stdint.h>

class LError
{
public:	
	
	LError ( const char * Type, const char * File, uint32_t Line );
	LError ( std :: string Type, std :: string File, uint32_t Line );
	
	virtual ~LError ();
	
	virtual std :: string GetErrorType () const;
	virtual std :: string GetErrorString ();
	
private:
	
	std :: string Type;
	std :: string File;
	uint32_t Line;
	
};

#endif
