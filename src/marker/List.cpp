#include "../Includes.hpp"

namespace far {
namespace marker {

const std::string List::model_file = "data/osg/cessnafire.osg";

List::List(std::string marker_args) : Marker(marker_args) {
	this->addChild(osgDB::readNodeFile(List::model_file));
}

void List::update() {
}

}}
