#include "EMarker.h"

EMarker::EMarker(osgART::Tracker* tracker, std::string marker_args, std::string model_file)
{
	this->label = new ELabel("key", "value");
	
	initMarker(tracker, marker_args);
	initModel(model_file);
	
	// attach the model to the marker
	osgART::attachDefaultEventCallbacks(_model, _marker);
	osgART::addEventCallback(_model, this);
}

osgART::Marker* EMarker::marker(){ return this->_marker; }
osg::MatrixTransform* EMarker::model() { return this->_model; }

osg::Vec3 EMarker::position() {
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
	_model->addChild(label->node());
	//_model->addChild(osgDB::readNodeFile(model_file));
	_model->getOrCreateStateSet()->setRenderBinDetails(100, "RenderBin");
}

void EMarker::operator() (osg::Node* node, osg::NodeVisitor* nv) {
	update();
	// must traverse the Node's subgraph
	traverse(node,nv);
}
