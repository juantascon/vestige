#include "EFactory.h"

EFactory* EFactory::_instance = 0;

EFactory::EFactory() { }

EFactory* EFactory::instance() {
	if (!_instance) {
		_instance = new EFactory();
	}
	return _instance;
}

void EFactory::initialize(osgART::Tracker* tracker) {
	this->tracker = tracker;
	
	new EList(tracker, "single;data/patt/patt.sample2;100;0;0");
	new EBlock(tracker, "single;data/patt/patt.hiro;100;0;0");
	new EBlock(tracker, "single;data/patt/patt.kanji;100;0;0");
	new EBlock(tracker, "single;data/patt/patt.sample1;100;0;0");
}

void EFactory::addModelsToCam(osg::Camera* cam) {
	for (int i = 0; i < EContainer::instance()->blocks()->size(); i++)
		cam->addChild( (*( EContainer::instance()->blocks() ))[i]->model());
	
	for (int i = 0; i < EContainer::instance()->lists()->size(); i++)
		cam->addChild( (*(EContainer::instance()->lists())) [i]->model());
}
