#include "Switch.hpp"
#include "../recursion/Step.hpp"

namespace vestige {
namespace marker {

Switch::Switch(std::string marker_args) : Marker(marker_args, "SWITCH") {
    captured = 0;
    
    this->paint();
}

void Switch::paint() {
    //this->add(osgDB::readNodeFile(core::Parameters::instance()->ROOT()+"data/model/switch.3ds"));
    this->add(osgDB::readNodeFile(core::Parameters::instance()->ROOT()+"/data/model/switch.osg"));
}

void Switch::alert(std::string message) {
    D(("ALERT [%s]: %s", message.c_str(), _id.c_str()));
    this->add(new draw::ToolTip(message, 80.0f));
}

void Switch::set_active(int active) {
    _active = active;
    if (!_active) { this->reset(); }
}

void Switch::update() {
    if (!_active) { return; }
    
    if (!this->visible()) {
        if (!captured) {
            recursion::StatusMessage* sm = recursion::Step::instance()->step();
            D(( sm->text().c_str() ));
            
            if ( sm->stop()) {
                set_active(0);
            }
            
            if (sm->message().size() >= 1) {
                alert(sm->message());
            }
            
            std::cout << std::endl << std::endl;
            
            captured = 1;
        }
        
        return;
    }
    
    captured = 0;
}

}}
