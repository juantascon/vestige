#include "EMarkerList.hpp"

const std::string EMarkerList::model_file = "data/osg/cessnafire.osg";

EMarkerList::EMarkerList(std::string marker_args) : EMarker(marker_args) {
	this->addChild(osgDB::readNodeFile(EMarkerList::model_file));
}

void EMarkerList::update() {
}

//TODO: mover esto a otro lugar
/*	EBlockVector *b = EContainer::instance()->blocks();
	
	this->clear();
	
	for (int i = 0; i < b->size(); i++) {
		if ( this->aligned( (*b)[i] ) ) {
			this->add( (*b)[i] );
		}
	}
*/
