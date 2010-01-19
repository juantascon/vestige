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
	
	gm->m_switch = new marker::Switch("single;data/patt/patt.kanji;100;0;0");
	gm->m_output = new marker::Output("single;data/patt/patt.hiro;100;0;0");
	
	gm->add( new marker::List("single;data/patt/patt.sample1;100;0;0", "l.sample1") );
	gm->add( new marker::List("single;data/patt/patt.sample2;100;0;0", "l.sample2") );
	
	gm->add( new marker::Block("single;data/patt/patt.a;100;0;0", "b.A", "B:A") );
	gm->add( new marker::Block("single;data/patt/patt.b;100;0;0", "b.B", "B:B") );
	gm->add( new marker::Block("single;data/patt/patt.c;100;0;0", "b.C", "B:C") );
	gm->add( new marker::Block("single;data/patt/patt.d;100;0;0", "b.D", "B:D") );
	gm->add( new marker::Block("single;data/patt/patt.f;100;0;0", "b.F", "B:F") );
	gm->add( new marker::Block("single;data/patt/patt.g;100;0;0", "b.G", "B:G") );
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
