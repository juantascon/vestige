set(SRCS
	Var.cpp
	marker/Manager.cpp marker/Marker.cpp marker/List.cpp marker/Block.cpp
	state/Node.cpp state/Block.cpp state/List.cpp state/State.cpp state/Manager.cpp
	Initializer.cpp Main.cpp
)

add_executable(${CMAKE_PROJECT_NAME} ${SRCS})
target_link_libraries(${CMAKE_PROJECT_NAME} osgART osgViewer osgText ${Boost_LIBRARIES})
