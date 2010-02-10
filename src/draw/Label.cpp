#include "Label.hpp"

namespace far {
namespace draw {

Label::Label(std::string value) {
	set_value(value);
}

std::string Label::get_value() { return _value; }
void Label::set_value(std::string value) { _value = value; }

osg::Node* Label::model() {
	/*osgText::Text3D* osgtext = new osgText::Text3D();
	osgtext->setFont("data/fonts/verdana.ttf");
	osgtext->setCharacterSize(100);
	osgtext->setCharacterDepth(10);
	osgtext->setAlignment( osgText::Text3D::CENTER_CENTER );*/
	
	osgText::Text* osgtext = new osgText::Text();
	osgtext->setFont("data/fonts/verdana.ttf");
	osgtext->setCharacterSize(100);
	osgtext->setAlignment( osgText::Text3D::CENTER_CENTER );
	//osgtext->setBackdropType(osgText::Text::OUTLINE);
	
	osgtext->setText( this->get_value() );
	
	osg::Geode* geode = new osg::Geode();
	geode->addDrawable(osgtext);
	
	return ( dynamic_cast<osg::Node*> (geode) );
}

}}
