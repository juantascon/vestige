#include "EBlock.hpp"

const std::string EBlock::model_file = "data/osg/cessna.osg";

EBlock::EBlock(std::string marker_args, std::string key) :
	EMarker(marker_args, EBlock::model_file)
{
	this->label = new ELabel(key, "empty");
	this->_model->addChild(label->node());
	
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
