#ifndef INCLUDE_IMPORTSDIF_H
#define INCLUDE_IMPORTSDIF_H
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
 * ImportSdif.h
 *
 * Definition of class ImportSdif, which reads an SDIF file.
 *
 * Lippold Haken, 4 July 2000
 * Lippold Haken, 20 October 2000, using IRCAM SDIF library
 * loris@cerlsoundgroup.org
 *
 * http://www.cerlsoundgroup.org/Loris/
 *
 */
#include <Loris_prefix.h>
#include "Partial.h"
#include <list>

#if !defined( NO_LORIS_NAMESPACE )
//	begin namespace
namespace Loris {
#endif

// ---------------------------------------------------------------------------
//	class ImportSdif
//	
class ImportSdif
{
//	-- instance variables --
	std::list<Partial> _partials;	//	collect Partials here

//	-- public interface --
public:
//	construction:
//	(let compiler generate destructor)
	ImportSdif( const char *infilename );
		
//	std::list< Partial > access:
	std::list<Partial> & partials( void ) { return _partials; }
	const std::list<Partial> & partials( void ) const { return _partials; }
	
//	-- private interface --
private:
	ImportSdif( const ImportSdif & other );
	ImportSdif  & operator = ( const ImportSdif & rhs );

};	//	end of class ImportSdif

#if !defined( NO_LORIS_NAMESPACE )
}	//	end of namespace Loris
#endif

#endif /* ndef INCLUDE_IMPORTSDIF_H */
