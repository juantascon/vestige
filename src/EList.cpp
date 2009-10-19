#include "EList.h"

const std::string EList::model_file = "data/osg/cessnafire.osg";

EList::EList(osgART::Tracker* tracker, std::string marker_args) :
	EMarker(tracker, marker_args, EList::model_file),
	blocks ()
{
	EContainer::instance()->addList(this);
}

void EList::add(EBlock *b) {
	blocks.push_back(b);
}

void EList::del(EBlock *b) {
}

void EList::clear() {
	blocks.clear();
}

void EList::print(){
	std::cout << "-------------" << std::endl;
	std::cout << "|           |" << std::endl;
	for (int i = 0; i < blocks.size(); i++){
		std::cout << " *" << "blocks[i]->label" << "*" << std::endl;
	}
}

int EList::block_aligned(EBlock* b) {
	osg::Vec3 bp = b->position();
	osg::Vec3 lp = this->position();
	
	osg::Vec3 dpos = bp - lp;
	
	std::cout << "bpos:" << bp << " lpos: " << lp << std::endl;
	//std::cout << dpos << std::endl;
	if (abs(dpos.x()) < 10) { return 1; }
	return 0;
}

void EList::update() {
	std::cout << "list pos changed" << std::endl;
	
	EBlockVector *v = EContainer::instance()->blocks();
	
	this->clear();
	
	for (int i = 0; i < v->size(); i++){
		if ( this->block_aligned( (*v)[i] ) ) {
			this->add( (*v)[i] );
		}
	}
	
	this->print();
}
