#include "Text.hpp"

namespace vestige {
namespace draw {

Text::Text(std::string value) : osgText::Text() {
	initialize(value);
}

void Text::initialize(std::string value) {
	setFont(core::Parameters::instance()->ROOT() + "/data/fonts/verdana.ttf");
	setAlignment( osgText::Text3D::CENTER_CENTER );
	//setBackdropType(osgText::Text::OUTLINE);
	setCharacterSize(100);
	setText(value);
}

osg::Geode* Text::wrap() {
	osg::Geode* g = new osg::Geode();
	g->addDrawable(this);
	return g;
}

}}
