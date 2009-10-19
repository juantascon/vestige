#include "EBlock.h"
#include "EContainer.h"

const std::string EBlock::model_file = "data/osg/cessna.osg";

EBlock::EBlock(osgART::Tracker* tracker, std::string marker_args) :
	EMarker(tracker, marker_args, EBlock::model_file)
{
	EContainer::instance()->addBlock(this);
}

void EBlock::update(){
	std::cout << "block pos changed" << std::endl;
}
