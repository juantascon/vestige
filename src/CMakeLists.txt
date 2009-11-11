set(SRCS ELabel.cpp EMarker.cpp EList.cpp EBlock.cpp EContainer.cpp EFactory.cpp Main.cpp)
add_executable(${CMAKE_PROJECT_NAME} ${SRCS})
target_link_libraries(${CMAKE_PROJECT_NAME} osgART osgViewer osgText)
