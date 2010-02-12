set(NAME osghud)

add_executable(${NAME} ${NAME})
target_link_libraries(${NAME} osgViewer osgText ${Boost_LIBRARIES})

