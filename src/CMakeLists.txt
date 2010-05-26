add_executable( vestige
  draw/Rectangle draw/Text draw/ToolTip
  core/Parameters core/GlobalStorage core/Initializer
  marker/Marker marker/List marker/Item marker/Switch marker/MarkerSet marker/GlobalMarkers
  state/Node state/List state/Item state/State state/NodeSet
  action/Action action/Pop action/Push action/PopPush action/Invalid action/Discard action/Create action/ActionSet
  rule/Rule rule/Pop rule/Push rule/PopPush rule/Discard rule/Create rule/RuleSet
  problem/Problem problem/ListReturn problem/PDebug
  problem/Reverse problem/Join problem/RemoveAll problem/Compress problem/InsertionSort
  recursion/StatusMessage recursion/Variable recursion/VariableSet recursion/Step
  Main
)

target_link_libraries(vestige osgART osgViewer osgText ${Boost_LIBRARIES})
