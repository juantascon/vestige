#include "Switch.hpp"
#include "../core/Supervisor.hpp"

namespace far {
namespace marker {

Switch::Switch(std::string marker_args) : Marker(marker_args, "SWITCH") {
	captured = 0;
	active = 1;
	
	this->addChild(osgDB::readNodeFile("data/model/switch.osg"));
}

void Switch::deactivate() {
	active = 0;
	this->resetModel();
}

void Switch::update() {
	if (!active) { return; }
	
	if (!this->visible()) {
		if (!captured) {
			core::Supervisor::instance()->step();
			std::cout << std::endl << std::endl << std::endl;
			
			captured = 1;
		}
		
		return;
	}
	
	captured = 0;
}

}}
