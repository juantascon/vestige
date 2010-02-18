#include "Initializer.hpp"
#include <osgART/GeometryUtils>

namespace vestige {
namespace core {

Initializer::Initializer() { }

Initializer* Initializer::instance() {
	return &boost::serialization::singleton<core::Initializer>::get_mutable_instance();
}

void Initializer::video() {
	int _video_id = osgART::PluginManager::instance()->load("osgart_video_artoolkit2");
	_video = dynamic_cast<osgART::Video*>(osgART::PluginManager::instance()->get(_video_id));
	
	if (!_video) { D(("Could not initialize video plugin!")); exit(-1); }
	
	_video->open();
}


void Initializer::tracker() {
	int _tracker_id = osgART::PluginManager::instance()->load("osgart_tracker_artoolkit2");
	_tracker = dynamic_cast<osgART::Tracker*>(osgART::PluginManager::instance()->get(_tracker_id));

	if (!_tracker) { D(("Could not initialize tracker plugin!")); exit(-1); }
	
	GlobalStorage::instance()->tracker = _tracker;
}

void Initializer::calibration() {
	_calibration = _tracker->getOrCreateCalibration();
	
	if (!_calibration->load("data/camera_para.dat")) {
			D(("Non existing or incompatible calibration file!"));
			exit(-1);
	}
	
	_tracker->setImage(_video);
}

void Initializer::camera() {
	_camera = _calibration->createCamera();
	
	osgART::VideoLayer* _layer = new osgART::VideoLayer();
	_layer->setSize(*_video);
	
	osgART::VideoGeode* _geode = new osgART::VideoGeode(osgART::VideoGeode::USE_TEXTURE_2D, _video);
	addTexturedQuad(*_geode,_video->s(),_video->t());
	_layer->addChild(_geode);
	
	_layer->getOrCreateStateSet()->setRenderBinDetails(0, "RenderBin");
	
	_camera->addChild(_layer);
	
	GlobalStorage::instance()->camera = _camera;
}

void Initializer::markers() {
	marker::GlobalMarkers* gm = marker::GlobalMarkers::instance();
	
	gm->m_switch = new marker::Switch("single;data/patt/artk/patt.kanji;100;0;0");
	gm->m_return = new marker::Return("single;data/patt/artk/patt.hiro;100;0;0");

	//DEMO
	gm->items_add( new marker::List("single;data/patt/artk/patt.sample1;100;0;0", "l.s1") );
	gm->items_add( new marker::List("single;data/patt/artk/patt.sample2;100;0;0", "l.s2") );
	gm->items_add( new marker::Block("single;data/patt/artk/patt.a;100;0;0", "b.a", "a") );
	gm->items_add( new marker::Block("single;data/patt/artk/patt.b;100;0;0", "b.b", "b") );
	gm->items_add( new marker::Block("single;data/patt/artk/patt.c;100;0;0", "b.c", "c") );
	gm->items_add( new marker::Block("single;data/patt/artk/patt.d;100;0;0", "b.d", "d") );
	gm->items_add( new marker::Block("single;data/patt/artk/patt.f;100;0;0", "b.f", "f") );
	gm->items_add( new marker::Block("single;data/patt/artk/patt.g;100;0;0", "b.g", "g") );
	
	/*
	gm->items_add( new marker::List("single;data/patt/artk/patt.a;100;0;0", "l.a") );
	gm->items_add( new marker::List("single;data/patt/artk/patt.b;100;0;0", "l.b") );
	gm->items_add( new marker::List("single;data/patt/artk/patt.c;100;0;0", "l.c") );
	gm->items_add( new marker::List("single;data/patt/artk/patt.d;100;0;0", "l.d") );
	gm->items_add( new marker::List("single;data/patt/artk/patt.f;100;0;0", "l.f") );
	gm->items_add( new marker::List("single;data/patt/artk/patt.g;100;0;0", "l.g") );
	
	//gm->items_add( new marker::Block("single;data/patt/artk/4x4_1.patt;100;0;0", "b.1", "1") );
	gm->items_add( new marker::Block("single;data/patt/artk/4x4_2.patt;100;0;0", "b.2", "2") );
	gm->items_add( new marker::Block("single;data/patt/artk/4x4_3.patt;100;0;0", "b.3", "3") );
	//gm->items_add( new marker::Block("single;data/patt/artk/4x4_4.patt;100;0;0", "b.4", "4") );
	//gm->items_add( new marker::Block("single;data/patt/artk/4x4_5.patt;100;0;0", "b.5", "5") );
	//gm->items_add( new marker::Block("single;data/patt/artk/4x4_6.patt;100;0;0", "b.6", "6") );
	gm->items_add( new marker::Block("single;data/patt/artk/4x4_7.patt;100;0;0", "b.7", "7") );
	//gm->items_add( new marker::Block("single;data/patt/artk/4x4_8.patt;100;0;0", "b.8", "8") );
	//gm->items_add( new marker::Block("single;data/patt/artk/4x4_9.patt;100;0;0", "b.9", "9") );
	//gm->items_add( new marker::Block("single;data/patt/artk/4x4_10.patt;100;0;0", "b.10", "10") );
	gm->items_add( new marker::Block("single;data/patt/artk/4x4_11.patt;100;0;0", "b.11", "11") );
	gm->items_add( new marker::Block("single;data/patt/artk/4x4_12.patt;100;0;0", "b.12", "12") );
	//gm->items_add( new marker::Block("single;data/patt/artk/4x4_12.patt;100;0;0", "b.13", "13") );
	//gm->items_add( new marker::Block("single;data/patt/artk/4x4_12.patt;100;0;0", "b.14", "14") );
	//gm->items_add( new marker::Block("single;data/patt/artk/4x4_12.patt;100;0;0", "b.15", "15") );
	//gm->items_add( new marker::Block("single;data/patt/artk/4x4_12.patt;100;0;0", "b.16", "16") );
	*/
}

void Initializer::viewer() {
	_viewer = new osgViewer::Viewer();
	
	_viewer->addEventHandler(new osgViewer::StatsHandler);
	_viewer->addEventHandler(new osgViewer::WindowSizeHandler);
	_viewer->addEventHandler(new osgViewer::ThreadingHandler);
	_viewer->addEventHandler(new osgViewer::HelpHandler);
	
	_viewer->setUpViewInWindow(0, 0, 800, 600);
	_viewer->realize();
}

void Initializer::root() {
	_root = new osg::Group();
	_root->addChild(_camera);
}

void Initializer::initialize(){
	video();
	tracker();
	calibration();
	camera();
	markers();
	viewer();
	root();
}

int Initializer::execute() {
	_viewer->setSceneData(_root);
	osgART::TrackerCallback::addOrSet(_root, _tracker);
	
	_video->start();
	return _viewer->run();
}

}}
