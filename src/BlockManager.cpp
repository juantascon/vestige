#include "BlockManager.h"

BlockManager* BlockManager::_instance = 0;

BlockManager::BlockManager() :
	blocks (),
	lists()
{
}

BlockManager* BlockManager::instance() {
	if (!_instance) {
		_instance = new BlockManager();
	}
	return _instance;
}

void BlockManager::initialize(osgART::Tracker* tracker) {
	this->tracker = tracker;
}

void BlockManager::addBlock(std::string marker_args) {
	EBlock* b = new EBlock(tracker, marker_args);
	blocks.push_back(b);
}


void BlockManager::addList(std::string marker_args) {
	EList* l = new EList(tracker, marker_args);
	lists.push_back(l);
}

void BlockManager::addModelsToCam(osg::Camera* cam) {
	for (int i = 0; i < blocks.size(); i++)
		cam->addChild(blocks[i]->model());
	
	for (int i = 0; i < lists.size(); i++)
		cam->addChild(lists[i]->model());
}

void BlockManager::blockUpdated(EBlock *b) {
}

void BlockManager::listUpdated(EList *l) {
	l->clear();
	
	for (int i = 0; i < blocks.size(); i++){
		if ( l->block_aligned(blocks[i]) ){
			l->add(blocks[i]);
		}
	}
	
	l->print();
	
}
