#include "BlockManager.h"

BlockManager::BlockManager(osgART::Tracker* tracker) : blocks (), lists() {
	this->tracker = tracker;
}

void BlockManager::addBlock(std::string marker_args) {
	EBlock* b = new EBlock(tracker, this, marker_args);
	blocks.push_back(b);
}

void BlockManager::addList(std::string marker_args) {
	EList* l = new EList(tracker, this, marker_args);
	lists.push_back(l);
}

void BlockManager::addModelsToCam(osg::Camera* cam) {
	for (int i = 0; i < blocks.size(); i++)
		cam->addChild(blocks[i]->model());
	
	for (int i = 0; i < lists.size(); i++)
		cam->addChild(lists[i]->model());
}

void BlockManager::operator() (osg::Node* node, osg::NodeVisitor* nv) {
	int count = 0;
	
	for (int i = 0; i < blocks.size(); i++)
		count += lists[0]->block_aligned(blocks[i]);
	
	std::cout << "y aligned: " << count << std::endl;
	std::cout << std::endl;
	
	// must traverse the Node's subgraph
	traverse(node,nv);
}

