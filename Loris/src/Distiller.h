#ifndef INCLUDE_DISTILLER_H
#define INCLUDE_DISTILLER_H
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
 * Distiller.h
 *
 * Definition of class Distiller.
 *
 * Kelly Fitz, 20 Oct 1999
 * loris@cerlsoundgroup.org
 *
 * http://www.cerlsoundgroup.org/Loris/
 *
 */

#include <PartialList.h>

//	begin namespace
namespace Loris {


// ---------------------------------------------------------------------------
//	class Distiller
//
//	Class Distiller represents an algorithm for "distilling" a group of
//	Partials that logically represent a single component into a single
//	Partial.
//	
//	The sound morphing algorithm in Loris requires that Partials in a
//	given source be labeled uniquely, that is, no two Partials can have
//	the same label. The Distiller enforces this condition. All Partials
//	identified with a particular frequency channel (see Channelizer), and,
//	therefore, having a common label, are distilled into a single Partial,
//	leaving at most a single Partial per frequency channel and label.
//	Channels that contain no Partials are not represented in the distilled
//	data. Partials that are not labeled, that is, Partials having label 0,
//	are unaffected by the distillation process. All unlabeled Partials
//	remain unlabeled and unmodified in the distilled partial set.
//	
//	Distillation modifies the Partial container (a PartialList). All
//	Partials in the distilled range having a common label are replaced by
//	a single Partial in the distillation process.
//
class Distiller
{
//	-- public interface --
public:
//	-- construction --
	Distiller( void );
	/*	Construct a new Distiller.
	 */
	 
	~Distiller( void );
	/*	Destroy this Distiller.
	 */
	
//	-- distillation --
	void distill( PartialList & container, PartialList::iterator dist_begin, 
				  PartialList::iterator dist_end );
	/*	Distill Partial on the specified half-open (STL-style) range in the
		specified container (PartialList). 
	 */
	 
	void distill( PartialList & container );
	/*	Distill all Partials in the specified container (PartialList).
	 */

	void operator() ( PartialList & container, PartialList::iterator dist_begin, 
					  PartialList::iterator dist_end )
		{ distill( container, dist_begin, dist_end ); }
	/*	Function call operator: same as distill( PartialList & container,
		PartialList::iterator dist_begin, PartialList::iterator dist_end ).
	 */

//	-- unimplemented --
private:
	Distiller( const Distiller & other );
	Distiller & operator= ( const Distiller & other );
	
};	//	end of class Distiller

}	//	end of namespace Loris

#endif /* ndef INCLUDE_DISTILLER_H */
