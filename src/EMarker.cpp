#include "EMarker.h"

EMarker::EMarker(osgART::Tracker* tracker, osg::NodeCallback* callback, std::string marker_args, std::string model_file)
{
	initMarker(tracker, marker_args);
	initModel(model_file);
	
	// attach the model to the marker
	osgART::attachDefaultEventCallbacks(_model, _marker);
	osgART::addEventCallback(_model, callback);
}

osgART::Marker* EMarker::marker(){ return this->_marker; }
osg::MatrixTransform* EMarker::model() { return this->_model; }

osg::Vec3 EMarker::getPos() {
	return this->_marker->getTransform().getTrans();
}

void EMarker::initMarker(osgART::Tracker* tracker, std::string args) {
	
	_marker = tracker->addMarker(args);
	if (!_marker)
	{
		osg::notify(osg::FATAL) << "Could not add marker!" << std::endl;
		exit(-1);
	}
	_marker->setActive(true);
}

void EMarker::initModel(std::string model_file) {
	
	_model = new osg::MatrixTransform();
	_model->addChild(osgDB::readNodeFile(model_file));
	_model->getOrCreateStateSet()->setRenderBinDetails(100, "RenderBin");
}

