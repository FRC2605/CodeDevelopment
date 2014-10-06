#ifndef SHS_2605_CONFIG_SECTION_H
#define SHS_2605_CONFIG_SECTION_H

#include "Jansson/jansson.h"

/* ConfigSection: A section of the configuration file. Typically, you create a sub-class of ConfigFile
* and manipulate the SectionNode from within it. The SectionNode is a Jansson object and requires the
* use of said API. This is entirely up to your own use.
*
* Note: The Name of the section must be unique for every seperate type and instance of section due to
* the way sections are stored in the JSON file.
*/

class ConfigSection
{
public:

	ConfigSection ( const char * Name );
	virtual ~ConfigSection ();
	
protected:
	
	virtual const char * GetName ();

	virtual json_t * GetValueObject ();
	virtual void SetLoadedValueObject ( json_t * ValueNode );

	virtual bool IsNodeNew ();

	json_t * SectionNode;
	const char * Name;
	bool New;
	
	friend class ConfigFile;

};

#endif
