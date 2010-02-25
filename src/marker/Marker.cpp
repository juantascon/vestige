#include "Marker.hpp"
#include "../core/GlobalStorage.hpp"

namespace vestige {
namespace marker {

Marker::Marker(std::string marker_args, std::string id)
{
    this->_id = id;
    this->set_valid(1);
    
    // create marker
    _marker = core::GlobalStorage::instance()->tracker->addMarker(marker_args);
    if (!_marker) {    D(("invalid marker")); exit(-1); }
    _marker->setActive(true);

    // create model
    _model = new osg::MatrixTransform();
    _model->getOrCreateStateSet()->setRenderBinDetails(100, "RenderBin");
    
    // attach the model to the marker
    osgART::attachDefaultEventCallbacks(_model, _marker);
    osgART::addEventCallback(_model, this);
    
    core::GlobalStorage::instance()->camera->addChild(_model);
}

osgART::Marker* Marker::marker() { return this->_marker; }
osg::MatrixTransform* Marker::model() { return this->_model; }
std::string Marker::id() { return this->_id; }

void Marker::add(osg::Node* child) {
    _model->addChild(child);
}

void Marker::reset() {
    _model->removeChildren(0, _model->getNumChildren());
}

int Marker::visible() {
    return _marker->valid();
}

osg::Vec3 Marker::position() {
    return _marker->getTransform().getTrans();
}

int Marker::under(Marker* m) {
    osg::Vec3 mpos = m->position();
    osg::Vec3 tpos = this->position();
    
    if (tpos.y() < mpos.y()) {
        return 1;
    }
    else {
        return 0;
    }
}

int Marker::over(Marker* m) {
    return ! under(m);
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

void Marker::set_valid(int valid) {
    _valid = valid;
}

void Marker::alert(std::string message) {
    D(("ALERT [%s]: %s", message.c_str(), _id.c_str()));
    
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
