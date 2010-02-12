#include "ToolTip.hpp"

namespace far {
namespace draw {

ToolTip::ToolTip(std::string value, float size) {
	initialize(value, size);
}

ToolTip::ToolTip(std::string value) {
	initialize(value, 35.0f);
}

void ToolTip::initialize(std::string value, float size) {
	Text* text = new Text(value);
	text->setCharacterSize(size);
	text->setPosition(osg::Vec3(0.0f, 100.0f, 10.1f));
	
	osg::BoundingBox* box = new osg::BoundingBox();
	box->expandBy(text->getBound());
	
	float extra = size / 5.0f;
	
	osg::Vec4* color = new osg::Vec4(1.0f, 1.0, 0.8f, 0.4f);
	
	float z = box->zMin()-0.1;
	draw::Rectangle* box_g = new draw::Rectangle (
		osg::Vec3(box->xMin()-extra, box->yMax()+extra, z),
		osg::Vec3(box->xMin()-extra, box->yMin()-extra, z),
		osg::Vec3(box->xMax()+extra, box->yMin()-extra, z),
		osg::Vec3(box->xMax()+extra, box->yMax()+extra, z),
		*color
	);
	
	draw::Rectangle* arrow = new draw::Rectangle (
		osg::Vec3(-0.1f, 0.0f, z),
		osg::Vec3(0.1f, 0.0f, z),
		osg::Vec3(box->xMax(), box->yMin()-extra, z),
		osg::Vec3(box->xMax()-( abs(box->xMax()-box->xMin()) / 3.0f), box->yMin()-extra, z),
		*color
	);
	
	this->addDrawable(text);
	this->addDrawable(box_g);
	this->addDrawable(arrow);
}

}}
