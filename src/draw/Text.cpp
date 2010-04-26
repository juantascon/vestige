#include "Text.hpp"

namespace vestige {
namespace draw {

Text::Text(std::string value) : osgText::Text() {
    initialize(value);
}

void Text::initialize(std::string value) {
    setFont(core::Parameters::instance()->ROOT() + "/data/fonts/verdana.ttf");
    setAlignment( CENTER_CENTER );
    //setBackdropType(osgText::Text::OUTLINE);
    setColor( osg::Vec4(0.0f, 0.0f, 0.0f, 1.0f) );
    setCharacterSize(100);
    setText(value);
}

osg::Geode* Text::wrap() {
    osg::Geode* g = new osg::Geode();
    g->addDrawable(this);
    return g;
}

}}
