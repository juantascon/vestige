#include "EBlock.hpp"

const std::string EBlock::model_file = "data/osg/cessna.osg";

EBlock::EBlock(std::string marker_args, std::string key) :
	EMarker(marker_args)
{
	this->label = new ELabel(key, "empty");
	
	this->addChild(label->node());
	this->addChild(osgDB::readNodeFile(EBlock::model_file));
	
	EContainer::instance()->addBlock(this);
}

void EBlock::print() {
	std::cout << "|*" << this->label->text() << "*|" << std::endl;
}

void EBlock::reset() {
	EListVector *l = EContainer::instance()->lists();
	
	this->list = 0;
	
	for (int i = 0; i < l->size(); i++) {
		if ( this->aligned( (*l)[i] ) ) {
			(*l)[i]->add(this);
		}
	}
}

void EBlock::update() {
	//std::cout << "block pos changed" << std::endl;
	this->reset();
	this->print();
}
