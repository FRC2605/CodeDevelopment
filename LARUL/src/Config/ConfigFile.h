#ifndef SHS_2605_CONFIG_FILE
#define SHS_2605_CONFIG_FILE

#include "Jansson/jansson.h"

#include "ConfigSection.h"
#include "../Logging/Logger.h"

#include <unistd.h>

/* ConfigFile: A robot configuration file which is useful for storing values and 
* settings that are tuned/set at runtime.
*/

class ConfigFile
{
public:
	
	// You probably won't need to alter this. Just make sure the directory exists before you use it!
	ConfigFile ( const char * FilePath = "/RobotConfig/Config.json" );
	~ConfigFile ();
	
	// Call this once to load the configuration file.
	bool Init ();

	/* Generally speaking, you'll only add config sections. Adding a section will load it's values
	* and make it a cantidate for recording when you call Write ().
	*/
	void AddConfigSection ( ConfigSection * Section );
	void RemoveConfigSection ( ConfigSection * Section );

	// Avoid calling this function periodically as flash memory has a limited number of reads and writes!
	bool Write ();

private:

	const char * FilePath;

	json_t * RootNode;

	bool Loaded;

	Logger * Log;

};

#endif
