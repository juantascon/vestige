set(NAME osggeometry)

add_executable(${NAME} ${NAME}.cpp)
target_link_libraries(${NAME} osgViewer osgText ${Boost_LIBRARIES})

