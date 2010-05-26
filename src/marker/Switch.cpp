#include "Switch.hpp"
#include "../recursion/Step.hpp"

namespace vestige {
namespace marker {

Switch::Switch(std::string marker_args) : Marker(marker_args, "SWITCH") {
    captured = 0;
    this->reset();
    this->paint();
}

void Switch::paint() {
    if (_active) {
        this->add(osgDB::readNodeFile(core::Parameters::instance()->ROOT()+"/data/model/camcorder/cam.ive"));
    }
    this->add(tooltip);
}

void Switch::reset() {
    Marker::reset();
    tooltip = new draw::ToolTip();
}

void Switch::alert(std::string message) {
    D(("ALERT [%s]: %s", message.c_str(), _id.c_str()));
    tooltip->alert(message);
}

void Switch::set_active(int active) {
    _active = active;
    if (!_active) {
        this->reset();
        this->paint();
    }
}

void Switch::capture() {
    recursion::StatusMessage* sm = recursion::Step::instance()->step();
    D(( "STATUSMESSAGE [[ %s ]]", sm->text().c_str() ));
    
    if ( sm->stop()) {
        set_active(0);
    }
    
    if (sm->message().size() >= 1) {
        alert(sm->message());
    }
    
    std::cout << std::endl << std::endl;
}

void Switch::update() {
    if (!_active) { return; }
    
    if (!this->visible()) {
        if (!captured) {
            capture();
            
            captured = 1;
        }
        
        return;
    }
    
    captured = 0;
}

}}
