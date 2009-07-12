#include "EList.h"

const std::string EList::model_file = "data/osg/cessnafire.osg";

EList::EList(osgART::Tracker* tracker, osg::NodeCallback* callback, std::string marker_args) :
	EMarker(tracker, callback, marker_args, EList::model_file)
{
}

int EList::block_aligned(EBlock* b) {
	osg::Vec3 bp = b->getPos();
	osg::Vec3 lp = this->getPos();
	
	osg::Vec3 dpos = bp - lp;
	
	std::cout << dpos << std::endl;
	if (abs(dpos.x()) < 10) { return 1; }
	return 0;
}
