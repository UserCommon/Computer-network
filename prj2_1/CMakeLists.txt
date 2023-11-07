cmake_minimum_required(VERSION 3.3)
project(prj2_1)

file( GLOB LIB_SOURCES *.cc )
file( GLOB LIB_HEADERS *.h )
add_library( YourLib ${LIB_SOURCES} ${LIB_HEADERS} )

file( GLOB APP_SOURCES *.cc )
foreach( testsourcefile ${APP_SOURCES} )
    # Cut off the file extension and directory path
    get_filename_component( testname ${testsourcefile} NAME_WE )
    add_executable( ${testname} ${testsourcefile} )
    target_link_libraries( ${testname} YourLib )
endforeach( testsourcefile ${APP_SOURCES} )

