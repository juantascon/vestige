#include "EIncludes.hpp"

const std::string EMarkerBlock::model_file = "data/osg/cessna.osg";

EMarkerBlock::EMarkerBlock(std::string marker_args, std::string key) : EMarker(marker_args)
{
	this->label = new ELabel(key, "empty");
	
	this->addChild(label->model());
	this->addChild(osgDB::readNodeFile(EMarkerBlock::model_file));
}

void EMarkerBlock::update() {
	EStateManager::instance()->capture();
}
