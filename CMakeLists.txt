cmake_minimum_required(VERSION 2.8.12)
project(Utilities)

#CMake scripts
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake )

#Find NetCDF packages
find_package( NETCDF )

#Bring the headers into the project
list( APPEND includePath "${CMAKE_CURRENT_SOURCE_DIR}/include/Containers"
			"${CMAKE_CURRENT_SOURCE_DIR}/include/IO"
			"${CMAKE_CURRENT_SOURCE_DIR}/include/ReadParams"
                          ${NETCDF_INCLUDE_DIRS} )

#Use file(GLOB...) for wildcard additions
file( GLOB SOURCES "src/IO/*.cpp" 
                   "src/ReadParams/*.cpp"
		   "src/Math/*.cpp" )

#Use file(GLOB...) for wildcard additions
file( GLOB HEADERS "include/Containers/*.h"
                   "include/IO/*.h"
                   "include/ReadParams/*.h"
		   "include/math/*.h" )

#Link libraries for executables

#demoContainers
#file( GLOB DEMO_CONTAINERS "demo/Containers/main.cpp" )
#add_executable( demoContainers ${DEMO_CONTAINERS} ${SOURCES} ${HEADERS} )
#target_link_libraries( demoContainers ${NETCDF_DOUBLE_LIB} )
#target_link_libraries( demoContainers ${NETCDF_CPP_LIB} )
#target_link_libraries( demoContainers ${NETCDF_FLOAT_LIB} )
#target_include_directories( demoContainers PUBLIC "$<BUILD_INTERFACE:${includePath}>" )

#demoIO
#file( GLOB DEMO_IO "demo/IO/main.cpp" )
#add_executable( demoIO ${DEMO_IO} ${SOURCES} ${HEADERS} )
#target_link_libraries( demoIO ${NETCDF_DOUBLE_LIB} )
#target_link_libraries( demoIO ${NETCDF_CPP_LIB} )
#target_link_libraries( demoIO ${NETCDF_FLOAT_LIB} )
#target_include_directories( demoIO PUBLIC "$<BUILD_INTERFACE:${includePath}>" )

#demoReadParams
file( GLOB DEMO_READPARAMS "demo/ReadParams/main.cpp" )
add_executable( demoReadParams ${DEMO_READPARAMS} ${SOURCES} ${HEADERS} )
target_link_libraries( demoReadParams ${NETCDF_DOUBLE_LIB} )
target_link_libraries( demoReadParams ${NETCDF_CPP_LIB} )
target_link_libraries( demoReadParams ${NETCDF_FLOAT_LIB} )
target_include_directories( demoReadParams PUBLIC "$<BUILD_INTERFACE:${includePath}>" )