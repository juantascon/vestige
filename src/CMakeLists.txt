set(SRCS
	ELabel.cpp
	EMarkerContainer.cpp EMarker.cpp EMarkerList.cpp EMarkerBlock.cpp
	ENode.cpp ENodeBlock.cpp ENodeList.cpp EState.cpp EStateManager.cpp
	EFactory.cpp Main.cpp
)

add_executable(${CMAKE_PROJECT_NAME} ${SRCS})
target_link_libraries(${CMAKE_PROJECT_NAME} osgART osgViewer osgText)
