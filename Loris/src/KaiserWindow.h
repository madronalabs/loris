#ifndef __Kaiser_window_header__
#define __Kaiser_window_header__
// ===========================================================================
//	KaiserWindow.h
//	
//	Class definition for factory class Loris::KaiserWindow.
//	KaiserWindow can't be instantiated, the class is just
//	a wrapper for the computation of Kaiser window samples.
//
//	-kel 14 Dec 99
//
// ===========================================================================

#include <vector>

#if !defined( NO_LORIS_NAMESPACE )
//	begin namespace
namespace Loris {
#endif


// ---------------------------------------------------------------------------
//	class KaiserWindow
//
//	Class KaiserWindow computes a Kaiser window function (see Kaiser and 
//	Schafer, 1980) for windowing FFT data.
//
//	This _should_ _not_ be a class.
//
class KaiserWindow
{
//	-- public interface --
public:
	static void create( std::vector< double > & samples, double shape );
	
	static double computeShape( double atten );
	static long computeLength( double width, double atten );

//	construction is not allowed:
private:
	KaiserWindow( void );
	
};	// end of class KaiserWindow

#if !defined( NO_LORIS_NAMESPACE )
}	//	end of namespace Loris
#endif

#endif 	// ndef __Kaiser_window_header__