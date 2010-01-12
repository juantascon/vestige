set(SRCS
	marker/Marker.cpp marker/List.cpp marker/Block.cpp marker/Switch.cpp marker/Var.cpp
	action/Action.cpp action/Pop.cpp action/Push.cpp action/PopPush.cpp action/Invalid.cpp action/Discard.cpp action/Detect.cpp
	rule/Rule.cpp rule/Pop.cpp rule/Push.cpp rule/PopPush.cpp rule/Discard.cpp rule/RuleSet.cpp
	state/Node.cpp state/Block.cpp state/List.cpp state/State.cpp state/Capture.cpp
	core/GlobalStorage.cpp core/Supervisor.cpp core/Initializer.cpp 
	Main.cpp
)

add_executable(${CMAKE_PROJECT_NAME} ${SRCS})
target_link_libraries(${CMAKE_PROJECT_NAME} osgART osgViewer osgText ${Boost_LIBRARIES})
