#include "Output.hpp"

#include "GlobalMarkers.hpp"

namespace far {
namespace marker {

Output::Output(std::string marker_args) : Marker(marker_args, "OUTPUT") {
	_value = 0;
}

Marker* Output::value() { return _value; }

osg::Node* Output::background() {
	if ( ! this->visible() || ! _value->visible() ) {
		return ( dynamic_cast<osg::Node*> (new osg::Geode()) );
	}
	
	float z = 2.0;
	float line_width = 10.0;
	
	osg::Vec4* color = new osg::Vec4(0, 0, 0, 0);
	
	//D(("VALUE: %s", _value->id.c_str()));
	
	osg::Vec3 value_pos = _value->position();
	osg::Vec3 output_pos = this->position();
	
	// LEFT LINE
	osg::Geometry* line = core::DrawHelper::instance()->rectangle (
		new osg::Vec3(abs(output_pos.x()-value_pos.x())+(line_width/2.0), abs(output_pos.y()-value_pos.y()), z),
		new osg::Vec3(0+(line_width/2.0), 0, z),
		new osg::Vec3(0-(line_width/2.0), 0, z),
		new osg::Vec3(abs(output_pos.x()-value_pos.x())-(line_width/2.0), abs(output_pos.y()-value_pos.y()), z),
		color
	);
	
	// Container
	osg::Geode* geode = new osg::Geode();
	geode->addDrawable(line);
	
	return ( dynamic_cast<osg::Node*> (geode) );
}


void Output::update_value() {
	_value = 0;
	
	if ( ! this->visible() ) {
		return;
	}
	
	BOOST_FOREACH( marker::Marker* m, *marker::GlobalMarkers::instance()->sort_y_axis() ) {
	 	if ( this->aligned(m) && this->under(m) ) {
			_value = m;
			return;
		}
	}
}

void Output::update() {
	if ( _value && this->aligned(_value) ) {
		this->resetModel();
		this->addChild(this->background());
		return;
	}
	
	update_value();
}

}}
