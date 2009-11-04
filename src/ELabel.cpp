#include "ELabel.hpp"

ELabel::ELabel(std::string key, std::string value) {
	set_key(key);
	set_value(value);
}

std::string ELabel::get_key() { return _key; }

std::string ELabel::get_value() { return _value; }

void ELabel::set_key(std::string key) {
	_key = key;
}

void ELabel::set_value(std::string value) {
	_value = value;
}

std::string ELabel::text() {
	return ( _key + " = " + _value );
}

osg::Node* ELabel::node() {
	osg::Geode* texts = new osg::Geode();
	texts->setName("name");
	
	osgText::Text* osgtext = new osgText::Text();
	osgtext->setText( this->text() );
	texts->addDrawable(osgtext);
	
	return ( dynamic_cast<osg::Node*> (texts) );
}
