#include "Includes.hpp"

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
	return ( _key + " = " + _value );
}

osg::Node* Var::model() {
	osg::Geode* texts = new osg::Geode();
	texts->setName("name");
	
	osgText::Text* osgtext = new osgText::Text();
	osgtext->setText( this->text() );
	texts->addDrawable(osgtext);
	
	return ( dynamic_cast<osg::Node*> (texts) );
}

}
