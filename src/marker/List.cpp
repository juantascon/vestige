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
	
	osg::Vec4Array* colors = new osg::Vec4Array();
	if (valid){
		colors->push_back(osg::Vec4(1, 1, 0, 0));
	}
	else{
		colors->push_back(osg::Vec4(1, 0, 0, 0));
	}
	
	// MAIN RECTANGLE
	osg::Geometry* rectangle = new osg::Geometry();
	
	osg::Vec3Array* rectangle_v = new osg::Vec3Array();
	rectangle_v->push_back( osg::Vec3(size+(align_factor/2.0), size, z) );
	rectangle_v->push_back( osg::Vec3(size+(align_factor/2.0), -size, z) );
	rectangle_v->push_back( osg::Vec3(-size-(align_factor/2.0), -size, z) );
	rectangle_v->push_back( osg::Vec3(-size-(align_factor/2.0), size, z) );
	
	rectangle->setVertexArray( rectangle_v );
	rectangle->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::POLYGON, 0, 4));
	rectangle->setColorArray(colors);
	rectangle->setColorBinding(osg::Geometry::BIND_OVERALL);
	
	
	// LEFT LINE
	osg::Geometry* line1 = new osg::Geometry();
	
	osg::Vec3Array* line1_v = new osg::Vec3Array();
	line1_v->push_back( osg::Vec3(-size-(align_factor/2.0), size+range, z) );
	line1_v->push_back( osg::Vec3(-size-(align_factor/2.0), -size, z) );
	line1_v->push_back( osg::Vec3(-size-line_width-(align_factor/2.0), -size, z) );
	line1_v->push_back( osg::Vec3(-size-line_width-(align_factor/2.0), size+range, z) );
	
	line1->setVertexArray( line1_v );
	line1->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::POLYGON, 0, 4));
	line1->setColorArray(colors);
	line1->setColorBinding(osg::Geometry::BIND_OVERALL);
	
	
	// RIGHT LINE
	osg::Geometry* line2 = new osg::Geometry();
	
	osg::Vec3Array* line2_v = new osg::Vec3Array();
	line2_v->push_back( osg::Vec3(size+(align_factor/2.0), size+range, z) );
	line2_v->push_back( osg::Vec3(size+(align_factor/2.0), -size, z) );
	line2_v->push_back( osg::Vec3(size+line_width+(align_factor/2.0), -size, z) );
	line2_v->push_back( osg::Vec3(size+line_width+(align_factor/2.0), size+range, z) );
	
	line2->setVertexArray( line2_v );
	line2->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::POLYGON, 0, 4));
	line2->setColorArray(colors);
	line2->setColorBinding(osg::Geometry::BIND_OVERALL);
	
	
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
