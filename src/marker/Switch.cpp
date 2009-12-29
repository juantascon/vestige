#include "Switch.hpp"
#include "../Supervisor.hpp"

namespace far {
namespace marker {

const std::string Switch::model_file = "data/model/switch.osg";
int Switch::captured = 0;

Switch::Switch(std::string marker_args, std::string id) : Marker(marker_args, id) {
	this->addChild(osgDB::readNodeFile(Switch::model_file));
}

void Switch::update() {
	if (this->visible()) {
		captured = 0;
	}
	else {
		if (!captured) {
			Supervisor::instance()->step();
			captured = 1;
		}
	}
}

}}
