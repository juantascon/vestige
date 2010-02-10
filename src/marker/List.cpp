#include "List.hpp"

namespace far {
namespace marker {

List::List(std::string marker_args, std::string id) : Marker(marker_args, id) {
	//this->addChild(osgDB::readNodeFile("data/model/list.osg"));
	this->addChild(this->background(1));
}

osg::Node* List::background(int valid) {
	int blocks_on_list = 4;
	
	float size = core::Parameters::instance()->BLOCK_SIZE();
	float align_factor = core::Parameters::instance()->ALIGN_FACTOR();
	float range = (size*2.0) * (float) blocks_on_list;
	float line_width = 20.0;
	float z = 1.0;
	
	
	osg::Vec4* color = new osg::Vec4(1, 1, 0, 0);
	if (!valid) { color =  new osg::Vec4(1, 0, 0, 0); }
	
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
	geode->addDrawable(rectangle);
	geode->addDrawable(line1);
	geode->addDrawable(line2);
	
	return ( dynamic_cast<osg::Node*> (geode) );
}

void List::update() {
}

}}
