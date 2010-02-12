#include "Block.hpp"

namespace far {
namespace marker {

Block::Block(std::string marker_args, std::string id, std::string key) : Marker(marker_args, id)
{
	this->key = key;
	
	this->addChild((new draw::Text(key))->wrap());
	this->addChild(this->background(1));
}

osg::Node* Block::background(int valid) {
	float size = core::Parameters::instance()->BLOCK_SIZE();
	float z = -2.0;
	
	osg::Vec4* color = new osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f);
	if (!valid) { color =  new osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f); }
	
	draw::Rectangle* rectangle = new draw::Rectangle(
		osg::Vec3(size, size, z),
		osg::Vec3(size, -size, z),
		osg::Vec3(-size, -size, z),
		osg::Vec3( -size, size, z),
		*color
	);
	
	// Container
	osg::Geode* geode = new osg::Geode();
	geode->addDrawable(rectangle);
	
	return ( dynamic_cast<osg::Node*> (geode) );
}

void Block::alert(std::string message) {
	D(("ALERT [%s]: %s", message.c_str(), id.c_str()));
	this->resetModel();
	
	this->addChild((new draw::Text(key))->wrap());
	this->addChild(new draw::ToolTip(message));
	this->addChild(this->background(0));
}

void Block::update() {
}

}}
