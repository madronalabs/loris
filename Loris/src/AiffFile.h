#ifndef __Loris_aiff_file__
#define __Loris_aiff_file__

// ===========================================================================
//	AiffFile.h
//	
//	Association of a sample buffer and the necessary additional info 
//	(sample rate, number of channels, and sample data size in bits)
//	to completely specify an AIFF samples file. Extends the generic
//	Loris::SamplesFile with AIFF i/o.
//
//	-kel 28 Sept 99
//
// ===========================================================================

#include "LorisTypes.h"
#include "ieee.h"
#include "SamplesFile.h"
#include <vector>
#include <string>

#if !defined( NO_LORIS_NAMESPACE )
//	begin namespace
namespace Loris {
#endif


class BinaryFile;

// ---------------------------------------------------------------------------
//	class AiffFile
//
//	The SampleBuffer must be provided by clients; it is not owned by 
//	the AiffFile.
//	
class AiffFile : public SamplesFile
{
public:
//	construction:
	AiffFile( double rate, int chans, int bits, std::vector< double > & buf );
	AiffFile( const std::string & filename, std::vector< double > & buf );
	AiffFile( BinaryFile & file, std::vector< double > & buf );
	
	AiffFile( const SamplesFile & other );
	
//	compiler-generated destructor is okay:
	//	~AiffFile( void );
	
//	reading and writing:
	void read( const std::string & filename );
	void read( BinaryFile & file );
	void write( const std::string & filename );
	void write( BinaryFile & file );
	
//	-- chunk types --
private:
	enum { 
		ContainerId = 'FORM', 
		AiffType = 'AIFF', 
		CommonId = 'COMM',
		SoundDataId = 'SSND'
	};
	
	struct CkHeader {
		Int_32 id;
		Uint_32 size;
	};
	
	struct ContainerCk
	{
		CkHeader header;
		Int_32 formType;
	};
	
	struct CommonCk
	{
		CkHeader header;
		Int_16 channels;			// number of channels 
		Int_32 sampleFrames;		// channel independent sample frames 
		Int_16 bitsPerSample;		// number of bits per sample 
		IEEE::extended80 srate;		// sampling rate IEEE 10 byte format 
	};
	
	struct SoundDataCk
	{
		CkHeader header;	
		Uint_32 offset;				
		Uint_32 blockSize;	
		//	sample frames follow
	};

//	-- helpers --
	//	reading:
	void readChunkHeader( BinaryFile & file, CkHeader & h );
	void readCommon( BinaryFile & file );
	void readContainer( BinaryFile & file );
	void readSampleData( BinaryFile & file );
	void readSamples( BinaryFile & file );

	//	writing:
	void writeCommon( BinaryFile & file );
	void writeContainer( BinaryFile & file );
	void writeSampleData( BinaryFile & file );
	void writeSamples( BinaryFile & file );
	
	//	data sizes:
	Uint_32 sizeofCommon( void );
	Uint_32 sizeofCkHeader( void );
	Uint_32 sizeofSoundData( void );

};	//	end of class AiffFile

#if !defined( NO_LORIS_NAMESPACE )
}	//	end of namespace Loris
#endif

#endif //	ndef __Loris_aiff_file__

