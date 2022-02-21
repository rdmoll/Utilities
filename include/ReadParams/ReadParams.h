/////////////////////////
//
//  FILE NAME:
//    ReadParams.h
//
//  AUTHOR: 
//    Ryan Moll
//
//  DATE CREATED:
//    December 13, 2020
//
//  LAST REVISION:
//    February 20, 2022
//
/////////////////////////

#ifndef ReadParams_h
#define ReadParams_h

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <map>
#include <math.h>
#include <string>
#include <vector>

namespace io
{

class ReadParams
{
public:
  ReadParams( const char*, const char* );
  ~ReadParams();
  
  std::map< std::string, int > iParam;
  std::map< std::string, double > dParam;
  std::map< std::string, std::string > strParam;
  
  bool readSuccessful;
  
protected:
  int iVal;
  double dVal;
  std::string delim;
  std::string line;
  std::string valStr;
  std::string valName;
  std::ifstream fileHandle;

  void ParseLine( void );
  bool AlphaFound( void );
  void StoreParams( void );
};

} // io

#endif  /* ReadParams_h */
