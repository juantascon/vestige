set(SRCS EBlock.cpp EContainer.cpp EFactory.cpp EList.cpp EMarker.cpp Main.cpp)
add_executable(${CMAKE_PROJECT_NAME} ${SRCS})
target_link_libraries(${CMAKE_PROJECT_NAME} osgART osgViewer)
