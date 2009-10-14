set(SRCS EMarker.cpp EBlock.cpp EList.cpp BlockManager.cpp Main.cpp)
add_executable(${CMAKE_PROJECT_NAME} ${SRCS})
target_link_libraries(${CMAKE_PROJECT_NAME} osgART osgViewer)
