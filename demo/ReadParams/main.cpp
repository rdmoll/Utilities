/////////////////////////
//
//  FILE NAME:
//    main.cpp
//
//  AUTHOR:
//    Ryan Moll
//
//  DATE CREATED:
//    February 20, 2022
//
//  LAST REVISION:
//    February 20, 2022
//
/////////////////////////

#include <iostream>
#include <ReadParams.h>

int main( int argc, const char * argv[] )
{
  const char* delimiter = "=";
  const char* filename = "./../demo/ReadParams/parametersTest.txt";
  io::ReadParams parameterFile( filename, delimiter );
  
  double value1 = parameterFile.dParam[ "value1" ];
  double value2 = parameterFile.dParam[ "value2" ];
  std::string value3 = parameterFile.strParam[ "value3" ];
  double value4 = parameterFile.dParam[ "value4" ];
  int value5 = parameterFile.iParam[ "value5" ];
  
  if( parameterFile.readSuccessful )
  {
    std::cout << "Read parameters from file : " << std::endl;
    std::cout << "  " << filename << std::endl;
    std::cout << std::endl;
    std::cout << "  value1 = " << value1 << std::endl;
    std::cout << "  value2 = " << value2 << std::endl;
    std::cout << "  value3 = " << value3 << std::endl;
    std::cout << "  value4 = " << value4 << std::endl;
    std::cout << "  value5 = " << value5 << std::endl;
  }
  
  return 0;
}

