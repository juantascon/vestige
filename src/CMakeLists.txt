add_executable( farcode
	marker/Marker marker/List marker/Block marker/Switch marker/Return marker/Var marker/GlobalMarkers
	action/Action action/Pop action/Push action/PopPush action/Invalid action/Discard action/Detect
	rule/Rule rule/Pop rule/Push rule/PopPush rule/Discard rule/RuleSet
	state/Node state/Block state/List state/State state/Capture
	problem/Problem problem/Reverse problem/Join problem/Variables
	core/DrawHelper core/Parameters core/GlobalStorage core/Supervisor core/Initializer
	Main
)

target_link_libraries(farcode osgART osgViewer osgText ${Boost_LIBRARIES})
