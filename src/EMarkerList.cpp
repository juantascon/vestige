#include "EIncludes.hpp"

const std::string EMarkerList::model_file = "data/osg/cessnafire.osg";

EMarkerList::EMarkerList(std::string marker_args) : EMarker(marker_args) {
	this->addChild(osgDB::readNodeFile(EMarkerList::model_file));
}

void EMarkerList::update() {
}
