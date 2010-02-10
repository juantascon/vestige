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
	//if ( ! this->visible() || ! _value->visible() ) {
	//	return ( dynamic_cast<osg::Node*> (new osg::Geode()) );
	//}
	
	int blocks_on_list = 1;
	float size = core::Parameters::instance()->BLOCK_SIZE();
	float align_factor = core::Parameters::instance()->ALIGN_FACTOR();
	float range = (size*2.0) * (float) blocks_on_list;
	float z = 2.0;
	float line_width = 10.0;
	
	osg::Vec4* color = new osg::Vec4(0, 0, 0, 0);
	
	//D(("VALUE: %s", _value->id.c_str()));
	
	osg::Vec3 value_pos = _value->position();
	osg::Vec3 this_pos = this->position();
	
	// LINE
	/*osg::Geometry* line = draw::Rectangle::instance()->create (
		new osg::Vec3(abs(this_pos.x()-value_pos.x())+(line_width/2.0), abs(this_pos.y()-value_pos.y()), z),
		new osg::Vec3(0+(line_width/2.0), 0, z),
		new osg::Vec3(0-(line_width/2.0), 0, z),
		new osg::Vec3(abs(this_pos.x()-value_pos.x())-(line_width/2.0), abs(this_pos.y()-value_pos.y()), z),
		color
	);*/
	
	osg::Geometry* line = draw::Rectangle::instance()->create (
		new osg::Vec3(value_pos.x()-this_pos.x()+(line_width/2.0), value_pos.y()-this_pos.y(), z),
		new osg::Vec3(0+(line_width/2.0), 0, z),
		new osg::Vec3(0-(line_width/2.0), 0, z),
		new osg::Vec3(value_pos.x()-this_pos.x()-(line_width/2.0), value_pos.y()-this_pos.y(), z),
		color
	);

	// RECTANGLE
	osg::Geometry* rectangle = draw::Rectangle::instance()->create (
		new osg::Vec3(size+(align_factor/2.0), size, z),
		new osg::Vec3(size+(align_factor/2.0), -size, z),
		new osg::Vec3(-size-(align_factor/2.0), -size, z),
		new osg::Vec3(-size-(align_factor/2.0), size, z),
		color
	);
	
	// LEFT LINE
	osg::Geometry* line1 = draw::Rectangle::instance()->create (
		new osg::Vec3(-size-(align_factor/2.0), size+range, z),
		new osg::Vec3(-size-(align_factor/2.0), -size, z),
		new osg::Vec3(-size-line_width-(align_factor/2.0), -size, z),
		new osg::Vec3(-size-line_width-(align_factor/2.0), size+range, z),
		color
	);
	
	// RIGHT LINE
	osg::Geometry* line2 = draw::Rectangle::instance()->create (
		new osg::Vec3(size+(align_factor/2.0), size+range, z),
		new osg::Vec3(size+(align_factor/2.0), -size, z),
		new osg::Vec3(size+line_width+(align_factor/2.0), -size, z),
		new osg::Vec3(size+line_width+(align_factor/2.0), size+range, z),
		color
	);
	
	// Container
	osg::Geode* geode = new osg::Geode();
	geode->addDrawable(line1);
	geode->addDrawable(line2);
	geode->addDrawable(rectangle);
	
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
