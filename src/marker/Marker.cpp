#include "Marker.hpp"
#include "Manager.hpp"

namespace far {
namespace marker {

Marker::Marker(std::string marker_args, std::string id)
{
	this->id = id;
	
	initMarker(marker_args);
	initModel();
	
	// attach the model to the marker
	osgART::attachDefaultEventCallbacks(_model, _marker);
	osgART::addEventCallback(_model, this);
	
	Manager::instance()->camera->addChild(_model);
	Manager::instance()->add(this);
}

void Marker::initMarker(std::string args) {
	_marker = Manager::instance()->tracker->addMarker(args);
	if (!_marker)
	{
		osg::notify(osg::FATAL) << "Could not add marker!" << std::endl;
		exit(-1);
	}
	_marker->setActive(true);
}

void Marker::initModel() {
	_model = new osg::MatrixTransform();
	_model->getOrCreateStateSet()->setRenderBinDetails(100, "RenderBin");
}

osgART::Marker* Marker::marker() { return this->_marker; }
osg::MatrixTransform* Marker::model() { return this->_model; }

void Marker::addChild(osg::Node* child) {
	_model->addChild(child);
}

int Marker::visible() {
	return this->marker()->valid();
}

osg::Vec3 Marker::position() {
	return this->_marker->getTransform().getTrans();
}

int Marker::aligned(Marker* m) {
	osg::Vec3 mpos = m->position();
	osg::Vec3 tpos = this->position();
	
	osg::Vec3 dpos = mpos - tpos;
	
	//D(("mpos: %s | tpos: %s", mpos.c_str(), tpos.c_str()))
	//std::cout << "mpos:" << bp << " tpos: " << lp << std::endl;
	//std::cout << "dpos: " << dpos << std::endl;
	//std::cout << "abs-x: " << abs(dpos.x()) << std::endl;
	
	if (abs(dpos.x()) < 40) { return 1; }
	return 0;
}

void Marker::alert() {
	
}

void Marker::operator() (osg::Node* node, osg::NodeVisitor* nv) {
	update();
	// must traverse the Node's subgraph
	traverse(node,nv);
}

}}