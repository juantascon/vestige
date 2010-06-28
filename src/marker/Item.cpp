#include "Item.hpp"

namespace vestige {
namespace marker {

Item::Item(std::string marker_args, std::string ar_id, std::string value) : Marker(marker_args, ar_id) {
    this->_value = value;
    
    if (core::Parameters::instance()->PHASE() != core::Parameters::PHASE_VARIABLES) {
        this->_label = value;
    }
    
    this->_top = 1;
    
    this->update();
}

std::string Item::value() { return this->_value; }
void Item::set_top(int top) { this->_top = top; }

void Item::paint() {
    float size = core::Parameters::instance()->MARKER_SIZE();
    float z = -1.0;
    
    osg::Vec4* color = new osg::Vec4(0.0f, 1.0f, 1.0f, 1.0f); // green
    if (!_active) { color =  new osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f); } // red
    if (!_top && core::Parameters::instance()->PHASE() != core::Parameters::PHASE_CONCRETE) {
        color = new osg::Vec4(1.0f, 1.0f, 0.0f, 1.0f); // yellow
    }
    
    if (this->label().empty() && core::Parameters::instance()->PHASE() == core::Parameters::PHASE_VARIABLES) {
        color = new osg::Vec4(1.0f, 1.0f, 0.0f, 1.0f); // yellow
    }
    
    draw::Rectangle* rectangle = new draw::Rectangle(
        osg::Vec3(size, size, z),
        osg::Vec3(size, -size, z),
        osg::Vec3(-size, -size, z),
        osg::Vec3(-size, size, z),
        *color
    );
    
    // Container
    osg::Geode* geode = new osg::Geode();
    geode->addDrawable(rectangle);
    this->add(geode);
    
    if (_top || core::Parameters::instance()->PHASE() == core::Parameters::PHASE_CONCRETE) {
        this->add((new draw::Text(_label))->wrap());
    }
}

void Item::alert(std::string message) {
    D(("ALERT [%s]: %s", message.c_str(), _id.c_str()));
    this->set_active(0);
    this->update();
    
    draw::ToolTip* t = new draw::ToolTip();
    t->alert(message, 35.0f);
    this->add(t);
}

void Item::update() {
    this->capture_info();
    if (! this->visible() ) { return; }
    
    this->model_reset();
    this->paint();
}

}}
