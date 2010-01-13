#include "Switch.hpp"
#include "../core/Supervisor.hpp"

namespace far {
namespace marker {

Switch::Switch(std::string marker_args, std::string id) : Marker(marker_args, id) {
	captured = 0;
	this->addChild(osgDB::readNodeFile("data/model/switch.osg"));
}

void Switch::update() {
	if (this->visible()) {
		captured = 0;
	}
	else {
		if (!captured) {
			core::Supervisor::instance()->step();
			captured = 1;
		}
	}
}

}}
