#ifndef __Loris_import__
#define __Loris_import__
// ===========================================================================
//	Import.h
//	
//	Class definition for Loris::Import, an abstract base class for
//	objects that import Partials into Loris.
//
//
//	-kel 10 Sept 99
//
// ===========================================================================
#include "LorisLib.h"
#include "Partial.h"
#include "Exception.h"

#include <list>

Begin_Namespace( Loris )

// ---------------------------------------------------------------------------
//	class Import
//
//	Import is an abstract base class for objects that bring Partials
//	into Loris. Most often, the Partials will be stored in a file somewhere,
//	but not necessarily. 
//
//	Import has a Template Method (GoF p.325), importPartials() for performing
//	the import. Primitive operations must be implemented by subclasses.
//
class Import : public PartialCollector
{
//	-- public Import interface --
public:
//	template method for importing partials:
	void importPartials( void );
	
//	-- primitve operations --
	//	check that source of Partials is valid or ready:
	virtual void verifySource( void ) {}
	
	//	prepare to import:
	virtual void beginImport( void ) {}
	
	//	derived classes must provide a mean of determining
	//	when the import loop should terminate:
	virtual boolean done( void ) = 0;
	
	//	derived classes must provide a means of reading 
	//	in a Partial and adding it to the list mPartials.
	virtual void getPartial( void ) = 0;	

	//	clean up after import:
	virtual void endImport( void ) {}

protected:
//	construction:
	Import( void );
	//virtual ~Import( void ) {}
};	//	end of class Import

// ---------------------------------------------------------------------------
//	class ImportException
//
//	Class of exceptions thrown when there is an error importing
//	Partials.
//
class ImportException : public Exception
{
public: 
	ImportException( const std::string & str, const std::string & where = "" ) : 
		Exception( std::string("Import Error -- ").append( str ), where ) {}
#if defined(__sgi) && ! defined(__GNUC__)
//	copying:
//	(exception objects are copied once when caught by reference,
//	or twice when caught by value)
//	This should be generated automatically by the compiler.
	ImportException( const ImportException & other ) : Exception( other ) {}
#endif // lame compiler
		
};	//	end of class ImportException


End_Namespace( Loris )

#endif	// ndef __Loris_import__

