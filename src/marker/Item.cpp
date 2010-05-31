#include "Item.hpp"

namespace vestige {
namespace marker {

Item::Item(std::string marker_args, std::string ar_id, std::string value) : Marker(marker_args, ar_id)
{
    this->_value = value;
    this->_top = 1;
    this->paint();
}

std::string Item::value() { return this->_value; }

void Item::set_top(int top) {
    this->_top = top;
    this->paint();
}

void Item::paint() {
    if (! this->visible() ) {
        return;
    }
    
    float size = core::Parameters::instance()->MARKER_SIZE();
    float z = -20.0;
    
    osg::Vec4* color = new osg::Vec4(0.0f, 1.0f, 1.0f, 1.0f);
    if (!_active) { color =  new osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f); }
    if (!_top) { color =  new osg::Vec4(1.0f, 1.0f, 0.0f, 1.0f); }
    
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
    
    this->model_reset();
    this->add(geode);
    if (_top) { this->add((new draw::Text(_value))->wrap()); }
}

void Item::alert(std::string message) {
    D(("ALERT [%s]: %s", message.c_str(), _id.c_str()));
    this->set_active(0);
    this->paint();
    
    draw::ToolTip* t = new draw::ToolTip();
    t->alert(message);
    this->add(t);
}

void Item::update() {
    this->paint();
}

}}
