set(SRCS
	marker/Marker marker/List marker/Block marker/Switch marker/Output marker/Var marker/GlobalMarkers
	action/Action action/Pop action/Push action/PopPush action/Invalid action/Discard action/Detect
	rule/Rule rule/Pop rule/Push rule/PopPush rule/Discard rule/RuleSet
	state/Node state/Block state/List state/State state/Capture state/GlobalStates
	problem/Problem problem/Reverse
	core/DrawHelper core/Parameters core/GlobalStorage core/Supervisor core/Initializer 
	Main
)

add_executable(${CMAKE_PROJECT_NAME} ${SRCS})
target_link_libraries(${CMAKE_PROJECT_NAME} osgART osgViewer osgText ${Boost_LIBRARIES})
