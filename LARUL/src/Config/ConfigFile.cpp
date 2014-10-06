#include "ConfigFile.h"

ConfigFile :: ConfigFile ( const char * FilePath ):
	FilePath ( FilePath ),
	Loaded ( false )
{

	Log = Logger :: GetInstance ();

};

// Initialize the configuration file. It loads any already present configuration information.
bool ConfigFile :: Init ()
{

	if ( Loaded )
		return true;

	json_error_t JSONError;
	RootNode = json_load_file ( FilePath, JSON_REJECT_DUPLICATES, & JSONError );

	if ( RootNode == NULL )
	{

		//Log -> Log ( Logger :: LOG_WARNING, "CONFIG_FILE: JSON Error: %s\n", JSONError.text );
		return false;

	}

	Loaded = true;

	return true;

};

// Add a configuration section. Adding a config section will load the section with pre-recorded values if they exist. 
void ConfigFile :: AddConfigSection ( ConfigSection * Section )
{

	json_t * SectionNode = json_object_get ( RootNode, Section -> GetName () );

	if ( SectionNode != NULL )
	{

		Section -> SetLoadedValueObject ( SectionNode );
		return;

	}

	json_object_set ( RootNode, Section -> GetName (), Section -> GetValueObject () );

};

// Remove a configuration section. This will prevent it from being re-written.
void ConfigFile :: RemoveConfigSection ( ConfigSection * Section )
{

	json_object_del ( RootNode, Section -> GetName () );

};

// Write all the configuration information availible to the previousley specified FilePath. This will contain the information of each added ConfigSection.
bool ConfigFile :: Write ()
{

	if ( json_dump_file ( RootNode, FilePath, JSON_INDENT ( 4 ) | JSON_SORT_KEYS ) == - 1 )
	{

		//Log -> Log ( Logger :: LOG_WARNING, "JSON Write failed!\n" );
		return false;
	
	}

	return true;

};

ConfigFile :: ~ConfigFile ()
{

	json_decref ( RootNode );

};
