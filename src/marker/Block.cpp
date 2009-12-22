#include "Block.hpp"

namespace far {
namespace marker {

const std::string Block::model_file = "data/osg/block.osg";

Block::Block(std::string marker_args, std::string id, std::string key) : Marker(marker_args, id)
{
	this->label = new Var(key, "empty");
	
	this->addChild(label->model());
	//this->addChild(osgDB::readNodeFile(Block::model_file));
	
	
	float boxSize = 100.0f;
	osg::ShapeDrawable* sd = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, boxSize / 2.0f), boxSize));
	sd->setColor(osg::Vec4(0, 0, 1, 1));
	osg::Geode* geode = new osg::Geode();
	geode->addDrawable(sd);
	this->addChild(geode);
}

void Block::update() {
}

}}
