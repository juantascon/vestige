#include "EIncludes.hpp"

EMarker::EMarker(std::string marker_args)
{
	initMarker(marker_args);
	initModel();
	
	// attach the model to the marker
	osgART::attachDefaultEventCallbacks(_model, _marker);
	osgART::addEventCallback(_model, this);
	
	EMarkerContainer::instance()->camera->addChild(_model);
	EMarkerContainer::instance()->add(this);
}

void EMarker::initMarker(std::string args) {
	_marker = EMarkerContainer::instance()->tracker->addMarker(args);
	if (!_marker)
	{
		osg::notify(osg::FATAL) << "Could not add marker!" << std::endl;
		exit(-1);
	}
	_marker->setActive(true);
}

void EMarker::initModel() {
	_model = new osg::MatrixTransform();
	_model->getOrCreateStateSet()->setRenderBinDetails(100, "RenderBin");
}

void EMarker::addChild(osg::Node* child) {
	_model->addChild(child);
}

osgART::Marker* EMarker::marker() { return this->_marker; }
osg::MatrixTransform* EMarker::model() { return this->_model; }

osg::Vec3 EMarker::position() {
	return this->_marker->getTransform().getTrans();
}

int EMarker::aligned(EMarker* m) {
	osg::Vec3 mp = m->position();
	osg::Vec3 tp = this->position();
	
	osg::Vec3 dpos = mp - tp;
	
	//std::cout << "mpos:" << bp << " tpos: " << lp << std::endl;
	//std::cout << dpos << std::endl;
	if (abs(dpos.x()) < 10) { return 1; }
	return 0;
}

void EMarker::operator() (osg::Node* node, osg::NodeVisitor* nv) {
	update();
	// must traverse the Node's subgraph
	traverse(node,nv);
}
