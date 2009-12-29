#include "List.hpp"

namespace far {
namespace marker {

const std::string List::model_file = "data/model/list.osg";

List::List(std::string marker_args, std::string id) : Marker(marker_args, id) {
	this->addChild(osgDB::readNodeFile(List::model_file));
}

void List::update() {
}

}}
