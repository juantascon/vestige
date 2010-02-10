#include "Initializer.hpp"
#include <osgART/GeometryUtils>

namespace far {
namespace core {

Initializer::Initializer() { }

Initializer* Initializer::instance() { return &boost::serialization::singleton<far::core::Initializer>::get_mutable_instance(); }

void Initializer::initVideo() {
	int _video_id = osgART::PluginManager::instance()->load("osgart_video_artoolkit2");
	video = dynamic_cast<osgART::Video*>(osgART::PluginManager::instance()->get(_video_id));
	
	if (!video)
	{
		osg::notify(osg::FATAL) << "Could not initialize video plugin!" << std::endl;
		exit(-1);
	}
	
	video->open();
}


void Initializer::initTracker() {
	int _tracker_id = osgART::PluginManager::instance()->load("osgart_tracker_artoolkit2");
	tracker = dynamic_cast<osgART::Tracker*>(osgART::PluginManager::instance()->get(_tracker_id));
	
	if (!tracker)
	{
		osg::notify(osg::FATAL) << "Could not initialize tracker plugin!" << std::endl;
		exit(-1);
	}
	
	GlobalStorage::instance()->tracker = tracker;
}

void Initializer::initCalibration() {
	calibration = tracker->getOrCreateCalibration();
	if (!calibration->load(std::string("data/camera_para.dat")))
	{
		osg::notify(osg::FATAL) << "Non existing or incompatible calibration file" << std::endl;
		exit(-1);
	}
	
	tracker->setImage(video);
}

void Initializer::initCamera() {
	camera = calibration->createCamera();
	//this->addModelsToCam(cam);
	
	osgART::VideoLayer* _layer = new osgART::VideoLayer();
	_layer->setSize(*video);
	
	osgART::VideoGeode* _geode = new osgART::VideoGeode(osgART::VideoGeode::USE_TEXTURE_2D, video);
	addTexturedQuad(*_geode,video->s(),video->t());
	_layer->addChild(_geode);
	
	_layer->getOrCreateStateSet()->setRenderBinDetails(0, "RenderBin");
	
	camera->addChild(_layer);
	GlobalStorage::instance()->camera = camera;
}

void Initializer::initMarkers() {
	marker::GlobalMarkers* gm = marker::GlobalMarkers::instance();
	
	gm->m_switch = new marker::Switch("single;data/patt/artk/patt.kanji;100;0;0");
	gm->m_return = new marker::Return("single;data/patt/artk/patt.hiro;100;0;0");

	/*
	gm->add( new marker::List("single;data/patt/artk/patt.sample1;100;0;0", "l.s1") );
	gm->add( new marker::List("single;data/patt/artk/patt.sample2;100;0;0", "l.s2") );
	gm->add( new marker::Block("single;data/patt/artk/patt.a;100;0;0", "b.a", "a") );
	gm->add( new marker::Block("single;data/patt/artk/patt.b;100;0;0", "b.b", "b") );
	gm->add( new marker::Block("single;data/patt/artk/patt.c;100;0;0", "b.c", "c") );
	gm->add( new marker::Block("single;data/patt/artk/patt.d;100;0;0", "b.d", "d") );
	gm->add( new marker::Block("single;data/patt/artk/patt.f;100;0;0", "b.f", "f") );
	gm->add( new marker::Block("single;data/patt/artk/patt.g;100;0;0", "b.g", "g") );
	*/
	
	gm->add( new marker::List("single;data/patt/artk/patt.a;100;0;0", "l.a") );
	gm->add( new marker::List("single;data/patt/artk/patt.b;100;0;0", "l.b") );
	gm->add( new marker::List("single;data/patt/artk/patt.c;100;0;0", "l.c") );
	gm->add( new marker::List("single;data/patt/artk/patt.d;100;0;0", "l.d") );
	gm->add( new marker::List("single;data/patt/artk/patt.f;100;0;0", "l.f") );
	gm->add( new marker::List("single;data/patt/artk/patt.g;100;0;0", "l.g") );
	
	//gm->add( new marker::Block("single;data/patt/artk/4x4_1.patt;100;0;0", "b.1", "1") );
	gm->add( new marker::Block("single;data/patt/artk/4x4_2.patt;100;0;0", "b.2", "2") );
	gm->add( new marker::Block("single;data/patt/artk/4x4_3.patt;100;0;0", "b.3", "3") );
	//gm->add( new marker::Block("single;data/patt/artk/4x4_4.patt;100;0;0", "b.4", "4") );
	//gm->add( new marker::Block("single;data/patt/artk/4x4_5.patt;100;0;0", "b.5", "5") );
	//gm->add( new marker::Block("single;data/patt/artk/4x4_6.patt;100;0;0", "b.6", "6") );
	gm->add( new marker::Block("single;data/patt/artk/4x4_7.patt;100;0;0", "b.7", "7") );
	//gm->add( new marker::Block("single;data/patt/artk/4x4_8.patt;100;0;0", "b.8", "8") );
	//gm->add( new marker::Block("single;data/patt/artk/4x4_9.patt;100;0;0", "b.9", "9") );
	//gm->add( new marker::Block("single;data/patt/artk/4x4_10.patt;100;0;0", "b.10", "10") );
	gm->add( new marker::Block("single;data/patt/artk/4x4_11.patt;100;0;0", "b.11", "11") );
	gm->add( new marker::Block("single;data/patt/artk/4x4_12.patt;100;0;0", "b.12", "12") );
	//gm->add( new marker::Block("single;data/patt/artk/4x4_12.patt;100;0;0", "b.13", "13") );
	//gm->add( new marker::Block("single;data/patt/artk/4x4_12.patt;100;0;0", "b.14", "14") );
	//gm->add( new marker::Block("single;data/patt/artk/4x4_12.patt;100;0;0", "b.15", "15") );
	//gm->add( new marker::Block("single;data/patt/artk/4x4_12.patt;100;0;0", "b.16", "16") );
}

void Initializer::initViewer() {
	viewer = new osgViewer::Viewer();
	
	viewer->addEventHandler(new osgViewer::StatsHandler);
	viewer->addEventHandler(new osgViewer::WindowSizeHandler);
	viewer->addEventHandler(new osgViewer::ThreadingHandler);
	viewer->addEventHandler(new osgViewer::HelpHandler);
	
	viewer->setUpViewInWindow(0, 0, 800, 600);
	viewer->realize();
}

void Initializer::initRoot() {
	root = new osg::Group();
	root->addChild(camera);
}

void Initializer::initialize(){
	initVideo();
	initTracker();
	initCalibration();
	initCamera();
	initMarkers();
	initViewer();
	initRoot();
}

int Initializer::execute() {
	viewer->setSceneData(root);
	osgART::TrackerCallback::addOrSet(root, tracker);
	
	video->start();
	return viewer->run();
}

}}
