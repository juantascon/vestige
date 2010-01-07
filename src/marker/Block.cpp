#include "Block.hpp"

namespace far {
namespace marker {

const std::string Block::model_file = "data/model/block.osg";

Block::Block(std::string marker_args, std::string id, std::string key) : Marker(marker_args, id)
{
	this->label = new Var(key, "empty");
	
	this->addChild(label->model());
	this->addChild(this->background(1));
}

osg::Node* Block::background(int valid) {
	float size = 110.0f;
	
	osg::Vec3Array* vertices = new osg::Vec3Array();
	vertices->push_back( osg::Vec3(size, size, -1) );
	vertices->push_back( osg::Vec3(size, -size, -1) );
	vertices->push_back( osg::Vec3(-size, -size, -1) );
	vertices->push_back( osg::Vec3( -size, size, -1) );
	
	osg::Geometry* rectangle = new osg::Geometry();	
	rectangle->setVertexArray( vertices );
	rectangle->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::POLYGON, 0, 4));
	
	osg::Vec4Array* colors = new osg::Vec4Array();
	if (valid){
		colors->push_back(osg::Vec4(0, 1, 0, 0));
	}
	else{
		colors->push_back(osg::Vec4(1, 0, 0, 0));
	}
	
	rectangle->setColorArray(colors);
	rectangle->setColorBinding(osg::Geometry::BIND_OVERALL);
	
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
