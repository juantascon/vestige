set(NAME osgtext3d)

add_executable(${NAME} ${NAME})
target_link_libraries(${NAME} osgViewer osgText ${Boost_LIBRARIES})

