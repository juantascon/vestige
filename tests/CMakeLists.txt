project (tests)
cmake_minimum_required(VERSION 2.6)

set(CMAKE_BUILD_TYPE Debug)

find_package( Boost 1.39 REQUIRED )
link_directories ( ${Boost_LIBRARY_DIRS} )
include_directories ( ${Boost_INCLUDE_DIRS} )


add_subdirectory(foreach)
add_subdirectory(list)
add_subdirectory(class)
add_subdirectory(splice)


