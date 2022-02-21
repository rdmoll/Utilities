/////////////////////////
//
//  FILE NAME:
//    ReadParams.cpp
//
//  AUTHOR: 
//    Ryan Moll
//
//  DATE CREATED:
//    December 21, 2020
//
//  LAST REVISION:
//    February 20, 2022
//
/////////////////////////

#include <ReadParams.h>

namespace io
{

// Method:
//   CONSTRUCTOR
// Argument list:
//   paramFile -- const char* -- name of parameter file (full path)
//   delimiter -- const char* -- delimiter separating value name from value in parameter file
// Description:
//   Creates ReadParams object. Reads and parses each line of a parameter file and stores the
//   value after the delimiter as a string, double, or integer.
ReadParams::ReadParams( const char* paramFile, const char* delimiter)
{
  delim = delimiter;
  fileHandle.open( paramFile );
  if( fileHandle.is_open() )
  {
    while( std::getline(fileHandle,line) )
    {
        ParseLine();
        StoreParams();
    }
    fileHandle.close();
    readSuccessful = true;
  }
  else
  {
    std::cout << "ERROR: Can't open parameter file" << std::endl;
    readSuccessful = false;
  }
}

ReadParams::~ReadParams()
{
  
}

// Method: 
//   ParseLine
// Arguments list:
//   None
// Description:
//   Parses line from parameter file based on specified delimiting character or string.
void ReadParams::ParseLine( void )
{
  valName = line.substr( 0,line.find(delim) );                                    // Parse out value name
  valName.erase( std::remove(valName.begin(),valName.end(),' '), valName.end() ); // Remove white space
  valStr = line.substr( line.find(delim) + delim.length() );                      // Parse out value
}

// Method:
//   AlphaFound
// Arguments list:
//   None
// Description:
//   Determines if letters are present in the string representing the value. If so the value is
//   treated as a string value. An exception is made for the letter 'e' because this can be used
//   in values in exponential form.
bool ReadParams::AlphaFound( void )
{
  const char alpha[] = { 'a', 'b', 'c', 'd', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', \
                         'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', \
                         'A', 'B', 'C', 'D', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', \
                         'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
  
  for( int i = 0; i < 50; i++)
  {
    if( valStr.find( alpha[ i ] ) < valStr.length() )
    {
      return true;
    }
  }
  
  return false;
}

// Method:
//   StoreParams
// Arguments list:
//   None
// Description:
//   Stores values as strings, doubles, or integers.
void ReadParams::StoreParams( void )
{
  if( AlphaFound() )    // Check if letters are present
  {
    valStr.erase( std::remove(valStr.begin(),valStr.end(),' '), valStr.end() );   // Remove white space
    strParam[valName] = valStr;   // Add as a string parameter
  }
  else
  {
    if( valStr.find('.') < valStr.length() )    // Check if there is a decimal point
    {
        dVal = atof( valStr.c_str() );    // Convert string to floating point
        dParam[ valName ] = dVal;         // Add as double parameter
    }
    else
    {
        iVal = atoi( valStr.c_str() );    // Convert to integer
        iParam[ valName ] = iVal;         // Add as integer parameter
    }
  }
}

} // io
