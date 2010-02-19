add_executable( vestige
	draw/Rectangle draw/Text draw/ToolTip
	core/Parameters core/GlobalStorage core/Initializer
	marker/Marker marker/List marker/Block marker/Switch marker/Return marker/MarkerSet marker/GlobalMarkers
	state/Node state/State state/NodeSet
	action/Action action/Pop action/Push action/PopPush action/Invalid action/Discard action/ActionSet
	rule/Rule rule/Pop rule/Push rule/PopPush rule/Discard rule/RuleSet
	problem/Problem problem/Reverse problem/Join
	recursion/Step
	Main
)

target_link_libraries(vestige osgART osgViewer osgText ${Boost_LIBRARIES})
