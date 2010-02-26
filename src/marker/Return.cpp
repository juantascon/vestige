#include "Return.hpp"

#include "GlobalMarkers.hpp"

namespace vestige {
namespace marker {

Return::Return(std::string marker_args) : Marker(marker_args, "RETURN")
{
    _value = 0;
}

Marker* Return::value() { return _value; }

void Return::paint() {
    this->reset();
    
    if (!_value) { return; }
    
    if ( !( this->visible() && _value->visible() ) ) {
        return;
    }
    
    float z = 2.0;
    osg::Vec4* color = new osg::Vec4(0.0f, 0.0f, 0.0f, 1.0f);
    
    // Rectangle
    float size = core::Parameters::instance()->MARKER_SIZE();
    
    draw::Rectangle* rectangle = new draw::Rectangle (
        osg::Vec3(size, size, z),
        osg::Vec3(size, -size, z),
        osg::Vec3(-size, -size, z),
        osg::Vec3(-size, size, z),
        *color
    );
    
    // LINE
    float line_width = 40.0;
    osg::Vec3 value_pos = _value->position();
    osg::Vec3 this_pos = this->position();
    
    draw::Rectangle* line = new draw::Rectangle(
        osg::Vec3(value_pos.x()-this_pos.x()+(line_width/2.0), value_pos.y()-this_pos.y(), z),
        osg::Vec3(0+(line_width/2.0), 0, z),
        osg::Vec3(0-(line_width/2.0), 0, z),
        osg::Vec3(value_pos.x()-this_pos.x()-(line_width/2.0), value_pos.y()-this_pos.y(), z),
        *color
    );
    
    // Container
    osg::Geode* geode = new osg::Geode();
    geode->addDrawable(line);
    geode->addDrawable(rectangle);
    
    this->add(geode);
}


void Return::update_value() {
    _value = NULL;
    
    marker::MarkerSet* _markers = marker::GlobalMarkers::instance()->markers_clone();
    _markers->filter_by_visible(1);
    _markers->filter_by_aligned_with_marker(this);
    _markers->sort_by_y_axis();
    
    if ( _markers->size() > 0 ) {
        //D(( "return: %s", _markers->text().c_str() ));
        _value = _markers->front();
    }
}

void Return::update() {
    this->paint();
    
    if ( ! this->visible() ) {
        return;
    }
    
    if ( _value && this->aligned(_value) ) {
        return;
    }
    
    update_value();
}

}}
