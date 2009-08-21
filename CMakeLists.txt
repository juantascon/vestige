cmake_minimum_required(VERSION 2.6)

project (demo1)

set(SRCS src/EMarker.cpp src/EBlock.cpp src/EList.cpp src/BlockManager.cpp src/Main.cpp)
add_executable(${CMAKE_PROJECT_NAME} ${SRCS})
target_link_libraries(${CMAKE_PROJECT_NAME} osgART osgViewer)

add_custom_target(run COMMAND test/run WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} COMMENT "Running ... ")
add_dependencies(run ${CMAKE_PROJECT_NAME})

