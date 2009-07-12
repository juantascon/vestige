cmake_minimum_required(VERSION 2.6)

project (test1)

set(exe_name test1)
set(SRCS src/EMarker.cpp src/EBlock.cpp src/EList.cpp src/BlockManager.cpp src/Main.cpp)

add_executable(${exe_name} ${SRCS})

target_link_libraries(${exe_name} osgART osgViewer)

