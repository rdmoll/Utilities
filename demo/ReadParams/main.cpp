#include <iostream>
#include <complex>

#include "Scalar1D.h"
#include "Scalar2D.h"
#include "Scalar3D.h"
#include "Transforms.h"
#include "MathOps.h"
#include "TestSolver.h"
#include "mpi.h"

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
  
  return 0;
}

