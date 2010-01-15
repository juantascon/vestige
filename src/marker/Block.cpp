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
	
	osg::Vec4* color = new osg::Vec4(0, 1, 0, 0);
	if (!valid) { color =  new osg::Vec4(1, 0, 0, 0); }
	
	osg::Geometry* rectangle = core::DrawHelper::instance()->rectangle (
		new osg::Vec3(size, size, z),
		new osg::Vec3(size, -size, z),
		new osg::Vec3(-size, -size, z),
		new osg::Vec3( -size, size, z),
		color
	);
	
	// Container
	osg::Geode* geode = new osg::Geode();
	geode->addDrawable(rectangle);
	
	return ( dynamic_cast<osg::Node*> (geode) );
}

void Block::alert(std::string message) {
	D(("ALERT [%s]: %s", message.c_str(), id.c_str()));
	this->resetModel();
	
	this->addChild(label->model());
	this->addChild(this->background(0));
}

void Block::update() {
}

}}
