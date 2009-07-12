#include "EBlock.h"

const std::string EBlock::model_file = "data/osg/cessna.osg";

EBlock::EBlock(osgART::Tracker* tracker, osg::NodeCallback* callback, std::string marker_args) :
	EMarker(tracker, callback, marker_args, EBlock::model_file)
{
}

