# This is the CMake script for compiling a CGAL application.


cmake_minimum_required(VERSION 3.1...3.15)
project( Spatial_sorting_Examples )


find_package(CGAL QUIET)

if ( CGAL_FOUND )

  # create a target per cppfile
  file(GLOB cppfiles RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
  foreach(cppfile ${cppfiles})
    create_single_source_cgal_program( "${cppfile}" )
  endforeach()

  find_package( TBB QUIET )
  if( TBB_FOUND )
    include( CGAL_target_use_TBB )
    CGAL_target_use_TBB( parallel_spatial_sort_3 )
 endif()   
else()
  
    message(STATUS "This program requires the CGAL library, and will not be compiled.")
  
endif()

