#include "EMarker.h"

EMarker::EMarker(std::string marker_args, std::string model_file)
{
	initMarker(marker_args);
	initModel(model_file);
	
	// attach the model to the marker
	osgART::attachDefaultEventCallbacks(_model, _marker);
	osgART::addEventCallback(_model, this);
}

void EMarker::initMarker(std::string args) {
	_marker = EContainer::instance()->tracker()->addMarker(args);
	if (!_marker)
	{
		osg::notify(osg::FATAL) << "Could not add marker!" << std::endl;
		exit(-1);
	}
	_marker->setActive(true);
}

void EMarker::initModel(std::string model_file) {
	_model = new osg::MatrixTransform();
	//_model->addChild(label->node());
	_model->addChild(osgDB::readNodeFile(model_file));
	_model->getOrCreateStateSet()->setRenderBinDetails(100, "RenderBin");
}


osgART::Marker* EMarker::marker(){ return this->_marker; }
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
