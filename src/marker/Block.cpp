#include "../Includes.hpp"

namespace far {
namespace marker {

const std::string Block::model_file = "data/osg/block.osg";

Block::Block(std::string marker_args, std::string key) : Marker(marker_args)
{
	this->label = new Var(key, "empty");
	
	this->addChild(label->model());
	this->addChild(osgDB::readNodeFile(Block::model_file));
}

void Block::update() {
}

}}
