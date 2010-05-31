#include "Switch.hpp"
#include "../recursion/Step.hpp"

namespace vestige {
namespace marker {

Switch::Switch(std::string marker_args) : Marker(marker_args, "SWITCH") {
    captured = 0;
    reset_next = 0;
    this->model_reset();
    this->paint();
}

void Switch::paint() {
    if (_active) {
        this->add(osgDB::readNodeFile(core::Parameters::instance()->ROOT()+"/data/model/camcorder/cam.osg"));
    }
    this->add(tooltip);
}

void Switch::model_reset() {
    Marker::model_reset();
    tooltip = new draw::ToolTip();
}

void Switch::alert(std::string message) {
    D(("ALERT [%s]: %s", message.c_str(), _id.c_str()));
    tooltip->alert(message);
}

void Switch::set_active(int active) {
    _active = active;
    if (!_active) {
        this->model_reset();
        this->paint();
    }
}

void Switch::capture() {
    if (reset_next) {
        reset_next = 0;
        recursion::Step::instance()->reset();
    }
    
    recursion::StatusMessage* sm = recursion::Step::instance()->step();
    D(( "STATUSMESSAGE [[ %s ]]", sm->text().c_str() ));
    
    switch(sm->type()) {
    case recursion::StatusMessage::STOP:
        set_active(0);
        break;
    case recursion::StatusMessage::CONTINUE:
        break;
    case recursion::StatusMessage::STANDBY:
        reset_next = 1;
        break;
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
