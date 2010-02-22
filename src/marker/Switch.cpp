#include "Switch.hpp"
#include "../recursion/Step.hpp"

namespace vestige {
namespace marker {

Switch::Switch(std::string marker_args) : Marker(marker_args, "SWITCH") {
	captured = 0;
	
	this->paint();
}

void Switch::paint() {
	this->reset();
	
	//this->add(osgDB::readNodeFile(core::Parameters::instance()->ROOT()+"data/model/switch.3ds"));
	this->add(osgDB::readNodeFile(core::Parameters::instance()->ROOT()+"data/model/switch.osg"));
}

void Switch::alert(std::string message) {
	D(("ALERT [%s]: %s", message.c_str(), _id.c_str()));
	this->paint();
	this->add(new draw::ToolTip(message, 80.0f));
}

void Switch::set_valid(int valid) {
	_valid = valid;
	if (!_valid) { this->reset(); }
}

void Switch::update() {
	if (!_valid) { return; }
	
	if (!this->visible()) {
		if (!captured) {
			recursion::Step::instance()->step();
			std::cout << std::endl << std::endl << std::endl;
			
			captured = 1;
		}
		
		return;
	}
	
	captured = 0;
}

}}
