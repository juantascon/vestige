#include "Return.hpp"

#include "GlobalMarkers.hpp"

namespace far {
namespace marker {

Return::Return(std::string marker_args) : Marker(marker_args, "RETURN")
{
	_value = 0;
}

Marker* Return::value() { return _value; }

osg::Node* Return::background() {
	float z = 2.0;
	float line_width = 10.0;
	
	osg::Vec4* color = new osg::Vec4(0.0f, 0.0f, 0.0f, 1.0f);
	
	//D(("VALUE: %s", _value->id.c_str()));
	
	osg::Vec3 value_pos = _value->position();
	osg::Vec3 this_pos = this->position();
	
	// LINE
	/*draw::Rectangle* line = draw::Rectangle(
		new osg::Vec3(abs(this_pos.x()-value_pos.x())+(line_width/2.0), abs(this_pos.y()-value_pos.y()), z),
		new osg::Vec3(0+(line_width/2.0), 0, z),
		new osg::Vec3(0-(line_width/2.0), 0, z),
		new osg::Vec3(abs(this_pos.x()-value_pos.x())-(line_width/2.0), abs(this_pos.y()-value_pos.y()), z),
		color
	);*/
	draw::Rectangle* line = new draw::Rectangle(
		osg::Vec3(value_pos.x()-this_pos.x()+(line_width/2.0), value_pos.y()-this_pos.y(), z),
		osg::Vec3(0+(line_width/2.0), 0, z),
		osg::Vec3(0-(line_width/2.0), 0, z),
		osg::Vec3(value_pos.x()-this_pos.x()-(line_width/2.0), value_pos.y()-this_pos.y(), z),
		*color
	);
	
	// Container
	osg::Geode* geode = new osg::Geode();
	if ( this->visible() && _value->visible() ) {
		geode->addDrawable(line);
	}
	
	return ( dynamic_cast<osg::Node*> (geode) );
}


void Return::update_value() {
	_value = 0;
	
	BOOST_FOREACH( marker::Marker* m, *marker::GlobalMarkers::instance()->sort_y_axis() ) {
		if ( this->aligned(m) && this->under(m) ) {
			_value = m;
			return;
		}
	}
}

void Return::update() {
	if ( ! this->visible() ) {
		return;
	}
	
	if ( _value && this->aligned(_value) ) {
		this->resetModel();
		this->addChild(this->background());
		return;
	}
	
	update_value();
}

}}