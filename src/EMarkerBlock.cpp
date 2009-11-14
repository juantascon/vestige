#include "EMarkerBlock.hpp"

const std::string EMarkerBlock::model_file = "data/osg/cessna.osg";

EMarkerBlock::EMarkerBlock(std::string marker_args, std::string key) : EMarker(marker_args)
{
	this->label = new ELabel(key, "empty");
	
	this->addChild(label->model());
	this->addChild(osgDB::readNodeFile(EMarkerBlock::model_file));
}

void EMarkerBlock::update() {
}

//TODO: move esto de aqui
/*
	EListVector *l = EContainer::instance()->lists();
	
	this->list = 0;
	
	for (int i = 0; i < l->size(); i++) {
		if ( this->aligned( (*l)[i] ) ) {
			(*l)[i]->add(this);
		}
	}
*/