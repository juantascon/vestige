cmake_minimum_required(VERSION 2.6)

project (demo1)

add_subdirectory(src)

#add_custom_target(run COMMAND test/run WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} COMMENT "Running ... ")
#add_dependencies(run ${CMAKE_PROJECT_NAME})

