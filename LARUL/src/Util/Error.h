#ifndef LARUL_ERROR_H
#define LARUL_ERROR_H

#define THROW_ERROR(x) throw Error ( x, __FILE__, __LINE__ )

#include <string>
#include <sstream>
#include <stdint.h>

class Error
{
public:	
	
	Error ( const char * Type, const char * File, uint32_t Line );
	Error ( std :: string Type, std :: string File, uint32_t Line );
	~Error ();
	
	virtual std :: string GetErrorType () const;
	virtual std :: string GetErrorString ();
	
private:
	
	std :: string Type;
	std :: string File;
	uint32_t Line;
	
};

#endif
