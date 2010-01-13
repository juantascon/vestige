#include "Block.hpp"

namespace far {
namespace marker {

Block::Block(std::string marker_args, std::string id, std::string key) : Marker(marker_args, id)
{
	this->label = new Var(key, "empty");
	
	this->addChild(label->model());
	//this->addChild(osgDB::readNodeFile("data/model/block.osg"));
	this->addChild(this->background(1));
}

osg::Node* Block::background(int valid) {
	float size = core::Parameters::instance()->BLOCK_SIZE();
	float z = -1.0;
	
	osg::Vec4Array* colors = new osg::Vec4Array();
	if (valid){
		colors->push_back(osg::Vec4(0, 1, 0, 0));
	}
	else{
		colors->push_back(osg::Vec4(1, 0, 0, 0));
	}
	
	// MAIN RECTANGLE
	osg::Geometry* rectangle = new osg::Geometry();
	
	osg::Vec3Array* rectangle_v = new osg::Vec3Array();
	rectangle_v->push_back( osg::Vec3(size, size, z) );
	rectangle_v->push_back( osg::Vec3(size, -size, z) );
	rectangle_v->push_back( osg::Vec3(-size, -size, z) );
	rectangle_v->push_back( osg::Vec3( -size, size, z) );
	
	rectangle->setVertexArray( rectangle_v );
	rectangle->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::POLYGON, 0, 4));
	rectangle->setColorArray(colors);
	rectangle->setColorBinding(osg::Geometry::BIND_OVERALL);
	
	// Container
	osg::Geode* geode = new osg::Geode();
	geode->addDrawable(rectangle);
	
	return ( dynamic_cast<osg::Node*> (geode) );
}

void Block::alert() {
	D(("ALERT: %s", id.c_str()));
	this->resetModel();
	
	this->addChild(label->model());
	this->addChild(this->background(0));
}

void Block::update() {
}

}}
