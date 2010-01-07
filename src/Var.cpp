#include "Var.hpp"

namespace far
{

Var::Var(std::string key, std::string value) {
	set_key(key);
	set_value(value);
}

std::string Var::get_key() { return _key; }

std::string Var::get_value() { return _value; }

void Var::set_key(std::string key) {
	_key = key;
}

void Var::set_value(std::string value) {
	_value = value;
}

std::string Var::text() {
	//return ( _key + " = " + _value );
	return ( _key  );
}

osg::Node* Var::model() {
	/*osgText::Text3D* osgtext = new osgText::Text3D();
	osgtext->setFont("data/fonts/verdana.ttf");
	osgtext->setCharacterSize(100);
	osgtext->setCharacterDepth(10);
	osgtext->setAlignment( osgText::Text3D::CENTER_CENTER );
	osgtext->setText( this->text() );
	osg::Geode* geode = new osg::Geode();
	geode->addDrawable(osgtext);*/
	
	osgText::Text* osgtext = new osgText::Text();
	osgtext->setFont("data/fonts/verdana.ttf");
	osgtext->setCharacterSize(100);
	osgtext->setAlignment( osgText::Text3D::CENTER_CENTER );
	//osgtext->setBackdropType(osgText::Text::OUTLINE);
	osgtext->setText( this->text() );
	osg::Geode* geode = new osg::Geode();
	geode->addDrawable(osgtext);
	
	return ( dynamic_cast<osg::Node*> (geode) );
}

}
