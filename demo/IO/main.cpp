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
  size_t Nx = 3;
  size_t Ny = 3;
  size_t Nsteps = 2;
  io::ioNetCDF testIO( "/Users/ryanmoll/Documents/dev/projects/HydroCode/tests/test_io.nc", Nx, Ny, 'w' );
  
  Scalar2D< double > testDataWrite( Nx, Ny );
  
  for( int ntime = 0; ntime < Nsteps; ntime++ )
  {
    for( int i = 0; i < Nx; i++ )
    {
      for( int j = 0; j < Ny; j++ )
      {
        testDataWrite( i, j ) = 1.0 * ( Ny * i + j + 1.0 );
      }
    }
    
    testIO.write_T( ntime, testDataWrite );
    testIO.write_u( ntime, testDataWrite );
  }
  
  bool pass = true;
  size_t Nx = 3;
  size_t Ny = 3;
  size_t Nsteps = 2;
  io::ioNetCDF testIO( "/Users/ryanmoll/Documents/dev/projects/HydroCode/tests/test_io.nc", Nx, Ny, 'r' );
  
  Scalar2D< double > testDataRead_T( Nx, Ny );
  Scalar2D< double > testDataRead_u( Nx, Ny );
  
  for( int ntime = 0; ntime < Nsteps; ntime++ )
  {
    testIO.read_T( ntime, testDataRead_T );
    testIO.read_u( ntime, testDataRead_u );
    
    for( int i = 0; i < Nx; i++ )
    {
      for( int j = 0; j < Ny; j++ )
      {
        if( testDataRead_T( i, j ) != 1.0 * ( Ny * i + j + 1.0 ) )
        {
          pass = false;
        }
        if( testDataRead_u( i, j ) != 1.0 * ( Ny * i + j + 1.0 ) )
        {
          pass = false;
        }
      }
    }
  }
  
  return 0;
}

