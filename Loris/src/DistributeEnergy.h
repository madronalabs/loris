#ifndef INCLUDE_DISTRIBUTEENERGY_H
#define INCLUDE_DISTRIBUTEENERGY_H
/*
 * This is the Loris C++ Class Library, implementing analysis, 
 * manipulation, and synthesis of digitized sounds using the Reassigned 
 * Bandwidth-Enhanced Additive Sound Model.
 *
 * Loris is Copyright (c) 1999-2000 by Kelly Fitz and Lippold Haken
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY, without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *
 * DistributeEnergy.h
 *
 * Definition of Loris function object DistributeEnergy.
 *
 * Kelly Fitz, 23 Jan 2000
 * loris@cerlsoundgroup.org
 *
 * http://www.cerlsoundgroup.org/Loris/
 *
 */
#include <Loris_prefix.h>
#include <list>

#if defined(__MWERKS__)
#include "Partial.h"
//	On Mac, can't get around including Partial.h unless make a 
//	class out of std::list< Partial > and its iterators that I can
//	forward-declare. CW seems not to be able to handle 
//	list<Partial>::iterator without the definition of Partial.
//	GNU, however, can handle it. Maybe in the new CW?
#endif

#if !defined( NO_LORIS_NAMESPACE )
//	begin namespace
namespace Loris {
#endif

class Partial;

// ---------------------------------------------------------------------------
//	class DistributeEnergy
//
//	Function object, has no instance variables or state. Not very useful
//	with STL though, as it takes three arguments. Could give it state by
//	constructing it with the range of receiving partials, and then it 
//	would be invoked with only one argument. Is it worth the overhead
//	of transfering the partials?
//
class DistributeEnergy
{
	double _maxdist;//	the maximum frequency distance (in Hz) over
					//	which energy will be redistributed; energy from
					//	a discarded Partial will be distributed only
					//	to Partials nearer in frequency than _maxdist
public:
	//	construction:
	explicit DistributeEnergy( double distanceHz );
	~DistributeEnergy(void);
	
	//	distribution:
	void distribute( const Partial & p, std::list<Partial>::iterator begin, 
										std::list<Partial>::iterator end ) const;
	
private: //	unimplemented:
	DistributeEnergy(void);
	DistributeEnergy(const DistributeEnergy &);
	
};	// end of class DistributeEnergy

#if !defined( NO_LORIS_NAMESPACE )
}	//	end of namespace Loris
#endif

#endif /* ndef INCLUDE_DISTRIBUTEENERGY_H */
