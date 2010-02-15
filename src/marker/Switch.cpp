#include "Switch.hpp"
#include "../core/Supervisor.hpp"

namespace vestige {
namespace marker {

Switch::Switch(std::string marker_args) : Marker(marker_args, "SWITCH") {
	captured = 0;
	active = 1;
	
	std::string msg = "INVALID INIT STATE:\nvariable L not found,\nexpected list with at least 2 items";
	this->addChild(new draw::ToolTip(msg, 35));
	this->addChild(osgDB::readNodeFile("data/model/switch.3ds"));
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
