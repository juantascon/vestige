#include "List.hpp"

namespace vestige {
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
	float z = -2.0;
	
	osg::Vec4* color = new osg::Vec4(1.0f, 1.0f, 0.0f, 1.0f);
	if (!valid) { color =  new osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f); }
	
	// RECTANGLE
	draw::Rectangle* rectangle = new draw::Rectangle(
		osg::Vec3(size+(align_factor/2.0), size, z),
		osg::Vec3(size+(align_factor/2.0), -size, z),
		osg::Vec3(-size-(align_factor/2.0), -size, z),
		osg::Vec3(-size-(align_factor/2.0), size, z),
		*color
	);
	
	// LEFT LINE
	draw::Rectangle* line1 = new draw::Rectangle(
		osg::Vec3(-size-(align_factor/2.0), size+range, z),
		osg::Vec3(-size-(align_factor/2.0), -size, z),
		osg::Vec3(-size-line_width-(align_factor/2.0), -size, z),
		osg::Vec3(-size-line_width-(align_factor/2.0), size+range, z),
		*color
	);
	
	// RIGHT LINE
	draw::Rectangle* line2 = new draw::Rectangle(
		osg::Vec3(size+(align_factor/2.0), size+range, z),
		osg::Vec3(size+(align_factor/2.0), -size, z),
		osg::Vec3(size+line_width+(align_factor/2.0), -size, z),
		osg::Vec3(size+line_width+(align_factor/2.0), size+range, z),
		*color
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
