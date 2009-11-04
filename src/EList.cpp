#include "EList.h"

const std::string EList::model_file = "data/osg/cessnafire.osg";

EList::EList(std::string marker_args) :
	EMarker(marker_args, EList::model_file),
	_blocks ()
{
	EContainer::instance()->addList(this);
}

void EList::add(EBlock *b) {
	_blocks.push_back(b);
}

void EList::del(EBlock *b) {
	//TODO: implementar
}

void EList::clear() {
	_blocks.clear();
}

void EList::print() {
	std::cout << "-------------" << std::endl;
	std::cout << "|           |" << std::endl;
	for (int i = 0; i < _blocks.size(); i++) {
		_blocks[i]->print();
	}
}

void EList::reset() {
	EBlockVector *b = EContainer::instance()->blocks();
	
	this->clear();
	
	for (int i = 0; i < b->size(); i++) {
		if ( this->aligned( (*b)[i] ) ) {
			this->add( (*b)[i] );
		}
	}
}

void EList::update() {
	//std::cout << "list pos changed" << std::endl;
	this->reset();
	this->print();
}
