add_executable( farcode
	marker/Marker marker/List marker/Block marker/Switch marker/Return marker/GlobalMarkers
	action/Action action/Pop action/Push action/PopPush action/Invalid action/Discard action/Detect
	rule/Rule rule/Pop rule/Push rule/PopPush rule/Discard rule/RuleSet
	state/Node state/Block state/List state/State state/Capture
	problem/Problem problem/Reverse problem/Join problem/Variables
	core/Parameters core/GlobalStorage core/Supervisor core/Initializer
	draw/Rectangle draw/Label
	Main
)

target_link_libraries(farcode osgART osgViewer osgText ${Boost_LIBRARIES})
