project (demo1)
cmake_minimum_required(VERSION 2.6)
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(src)

#add_custom_target(run COMMAND test/run WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} COMMENT "Running ... ")
#add_dependencies(run ${CMAKE_PROJECT_NAME})

