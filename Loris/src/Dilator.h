#ifndef __Loris_dilator__
#define __Loris_dilator__
// ===========================================================================
//	Dilator.h
//
//	Dilator is a class of objects for temporally dilating and compressing
//	Partials by specifying initial and target times of temporal features.
//
//	-kel 26 Oct 99
//
// ===========================================================================
#include "LorisLib.h"

#include <vector>
#include <set>

Begin_Namespace( Loris )

class Partial;

// ---------------------------------------------------------------------------
//	class Dilator
//
//	HEY provide access to the PartialIterator, like others.
//
class Dilator
{
//	-- construction --
public:
	Dilator( void ) {}
	Dilator( const std::vector< double > & init, const std::vector< double > & tgt );

//	constructor from iterators:
//	If template members aren't available, accept only vector iterators.
#if !defined(No_template_members)
	template < class Iter1, class Iter2 >
	Dilator( Iter1 ibegin, Iter2 tbegin, int n )
#else
	Dilator( std::vector< double >::const_iterator ibegin, 
			 std::vector< double >::const_iterator tbegin, 
			 int n )
#endif
	{
		setTimePoints( ibegin, tbegin, n );
	}
	
	//	use compiler-generated:
	// Dilator( const Dilator & );
	// ~Dilator( void );
	
//	-- time-point access and mutation --
	const std::set< double > & initialTimePoints( void ) const { return _initial; }
	const std::set< double > & targetTimePoints( void ) const { return _target; }
	std::set< double > & initialTimePoints( void ) { return _initial; }
	std::set< double > & targetTimePoints( void ) { return _target; }
	
//	template time point specification from iterators:
//	If template members aren't available, accept only vector iterators.
#if !defined(No_template_members)
	template < class Iter1, class Iter2 >
	void setTimePoints( Iter1 ibegin, Iter2 tbegin, int n )
#else
	void setTimePoints( std::vector< double >::const_iterator ibegin, 
						std::vector< double >::const_iterator tbegin, int n )
#endif
	{
		while ( n > 0 ) {
			_initial.insert( *(ibegin++) );
			_target.insert( *(tbegin++) );
			--n;
		}
	}
	
//	-- dilation --
	Partial & dilate( Partial & p ) const;
	Partial & operator()( Partial & p ) const { return dilate( p ); }
	
//	template dilation of an iterator range:
//	(only if template members are allowed)
#if !defined(No_template_members)
	template < class Iter >
	void dilate( Iter begin, Iter end ) const
	{
		while ( begin != end )
			dilate( *(begin++) );
	}
	
	template < class Iter >
	void operator() ( Iter begin, Iter end ) const { dilate( begin, end ); }
#endif
	
//	-- instance variables --
private:
	std::set< double > _initial;
	std::set< double > _target;
		
};	//	end of class Dilator


End_Namespace( Loris )

#endif	// ndef __Loris_dilator__