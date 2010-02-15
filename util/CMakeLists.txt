add_custom_target(run ALL COMMAND util/run  WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY} COMMENT "Running ... ")
add_dependencies(run vestige)
