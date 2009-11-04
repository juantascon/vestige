#include "EContainer.h"

EContainer* EContainer::_instance = 0;

EContainer::EContainer() :
	_blocks (),
	_lists()
{
}

EContainer* EContainer::instance() {
	if (!_instance) {
		_instance = new EContainer();
	}
	return _instance;
}

void EContainer::addBlock(EBlock *b) {
	_blocks.push_back(b);
}

EBlockVector* EContainer::blocks() {
	return &_blocks;
}

void EContainer::addList(EList *l) {
	_lists.push_back(l);
}

EListVector* EContainer::lists() {
	return &_lists;
}

void EContainer::setTracker(osgART::Tracker* tracker) {
	this->_tracker = tracker;
}

osgART::Tracker* EContainer::tracker() {
	return _tracker;
}
