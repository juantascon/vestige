#include "Initializer.hpp"
#include <osgART/GeometryUtils>

namespace far
{

Initializer::Initializer() { }

Initializer* Initializer::instance() { return &boost::serialization::singleton<far::Initializer>::get_mutable_instance(); }

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
	
	marker::Manager::instance()->tracker = tracker;
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
	marker::Manager::instance()->camera = camera;
}

void Initializer::initMarkers() {
	new marker::Switch("single;data/patt/patt.kanji;100;0;0", "switch");
	
	new marker::List("single;data/patt/patt.hiro;100;0;0", "l.hiro");
	new marker::List("single;data/patt/patt.sample1;100;0;0", "l.sample1");
	new marker::List("single;data/patt/patt.sample2;100;0;0", "l.sample2");
	
	new marker::Block("single;data/patt/multi/patt.a;100;0;0", "b.A", "A");
	new marker::Block("single;data/patt/multi/patt.b;100;0;0", "b.B", "B");
	new marker::Block("single;data/patt/multi/patt.c;100;0;0", "b.C", "C");
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

void initRuleSet() {
	//rule::RuleSet::instance()->add(new rule::Pop("b.C", "l.sample1"));
	rule::RuleSet::instance()->add(new rule::PopPush("b.C", "l.hiro", "l.sample1"));
	rule::RuleSet::instance()->add(new rule::PopPush("b.B", "l.hiro", "l.sample1"));
	rule::RuleSet::instance()->add(new rule::PopPush("b.A", "l.hiro", "l.sample1"));
}

void Initializer::initialize(){
	initVideo();
	initTracker();
	initCalibration();
	initCamera();
	initMarkers();
	initViewer();
	initRoot();
	initRuleSet();
}

int Initializer::execute() {
	viewer->setSceneData(root);
	osgART::TrackerCallback::addOrSet(root, tracker);
	
	video->start();
	return viewer->run();
}

}
