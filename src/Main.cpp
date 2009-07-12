#include "BlockManager.h"

#include <osgART/GeometryUtils>

osg::Group* createImageBackground(osg::Image* video) {
	
	osgART::VideoLayer* _layer = new osgART::VideoLayer();
	_layer->setSize(*video);
	
	osgART::VideoGeode* _geode = new osgART::VideoGeode(osgART::VideoGeode::USE_TEXTURE_2D, video);
	addTexturedQuad(*_geode,video->s(),video->t());
	_layer->addChild(_geode);
	
	_layer->getOrCreateStateSet()->setRenderBinDetails(0, "RenderBin");
	
	return _layer;
}

osgART::Video* createVideo() {
	
	int _video_id = osgART::PluginManager::instance()->load("osgart_video_artoolkit2");
	osgART::Video* _video = dynamic_cast<osgART::Video*>(osgART::PluginManager::instance()->get(_video_id));
	
	if (!_video)
	{
		osg::notify(osg::FATAL) << "Could not initialize video plugin!" << std::endl;
		exit(-1);
	}
	
	_video->open();
	
	return _video;
}

osgART::Tracker* createTracker() {
	
	int _tracker_id = osgART::PluginManager::instance()->load("osgart_tracker_artoolkit2");
	osgART::Tracker* _tracker = dynamic_cast<osgART::Tracker*>(osgART::PluginManager::instance()->get(_tracker_id));
	
	if (!_tracker)
	{
		osg::notify(osg::FATAL) << "Could not initialize tracker plugin!" << std::endl;
		exit(-1);
	}
	
	return _tracker;
}


int main(int argc, char* argv[]) {
	
	osg::ref_ptr<osgART::Video> video = createVideo();
	osg::ref_ptr<osgART::Tracker> tracker = createTracker();
	
	// load a calibration file
	osg::ref_ptr<osgART::Calibration> calibration = tracker->getOrCreateCalibration();
	if (!calibration->load(std::string("data/camera_para.dat")))
	{
		osg::notify(osg::FATAL) << "Non existing or incompatible calibration file" << std::endl;
		exit(-1);
	}
	
	// set the image source for the tracker
	tracker->setImage(video.get());
	
	// the camera
	osg::ref_ptr<osg::Camera> cam = calibration->createCamera();
	
	osg::ref_ptr<BlockManager> bm = new BlockManager( tracker.get() );
	bm->addList("single;data/patt/patt.sample2;100;0;0");
	bm->addBlock("single;data/patt/patt.hiro;100;0;0");
	bm->addBlock("single;data/patt/patt.kanji;100;0;0");
	bm->addBlock("single;data/patt/patt.sample1;100;0;0");
	
	bm->addModelsToCam(cam);
	cam->addChild(createImageBackground(video.get()));
	
	// create the viewer
	osgViewer::Viewer viewer;
	viewer.addEventHandler(new osgViewer::StatsHandler);
	viewer.addEventHandler(new osgViewer::WindowSizeHandler);
	viewer.addEventHandler(new osgViewer::ThreadingHandler);
	viewer.addEventHandler(new osgViewer::HelpHandler);
	
	// create a root node
	osg::ref_ptr<osg::Group> root = new osg::Group;
	root->addChild(cam.get());
	
	// attach root node to scene
	viewer.setSceneData(root.get());
	osgART::TrackerCallback::addOrSet(root.get(), tracker.get());
	
	// execute
	video->start();
	return viewer.run();
}

