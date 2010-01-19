#include "Marker.hpp"
#include "../core/GlobalStorage.hpp"

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
	
	core::GlobalStorage::instance()->camera->addChild(_model);
}

void Marker::initMarker(std::string args) {
	_marker = core::GlobalStorage::instance()->tracker->addMarker(args);
	if (!_marker)
	{
		osg::notify(osg::FATAL) << "Could not add marker!" << std::endl;
		return;
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

void Marker::resetModel() {
	_model->removeChildren(0, _model->getNumChildren());
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
	
	return (abs(dpos.x()) < core::Parameters::instance()->ALIGN_FACTOR());
}

void Marker::alert(std::string message) {
	D(("ALERT [%s]: %s", message.c_str(), id.c_str()));
	this->resetModel();
	
	/*float boxSize = 100.0f;
	osg::ShapeDrawable* sd = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, boxSize / 2.0f), boxSize));
	sd->setColor(osg::Vec4(1, 0, 0, 1));
	osg::Geode* geode = new osg::Geode();
	geode->addDrawable(sd);
	this->addChild(geode);*/
}

void Marker::operator() (osg::Node* node, osg::NodeVisitor* nv) {
	update();
	// must traverse the Node's subgraph
	traverse(node,nv);
}

}}
