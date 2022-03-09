# Utilities

# ReadParams
  DESCRIPTION :
    This code reads parameters from a parameter file, and then makes those parameters
    available to the user.
    
  USAGE :
    Create a parameter file where each line has the format:
    [value name] [delimiter string] [value],
    then provide the name of this parameter file as the first input to the ReadParams 
    constructor. The second constructor parameter is the delimiter string. See the 
    file demo/ReadParams/parametersTest.txt for an example parameter file.
    
    The ReadParams class instance reads and parses the parameter file in the 
    constructor, and the parameters are separated into strings, doubles, and integers.
    The parameters values are accessed through public std::map objects for each of the
    three supported data types (called strParam, dParam, and iParam). To access the
    parameters stored in these maps simply pass the value name from the parameter file
    as the key in the appropriate map object.
    
    See the "demo" folder for an example of how the use the ReadParams class.
    
# Scalar1D, Scalar2D, and Scalar3D
  DESCRIPTION :
    These classes serve as representations of 1D, 2D, and 3D arrays. Array elements can 
    be identified using the appropiate indicies for the dimension of the array. The
    underlying data are contained in a private unique_ptr defined in each ScalarXD 
    object.
    
  USAGE :
  
# ioNetCDF
  DESCRIPTION :
    This code serves as a wrapper around the NetCDF functions.
    
