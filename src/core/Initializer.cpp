#include "Initializer.hpp"
#include <osgART/GeometryUtils>

#include "GlobalStorage.hpp"
#include "../marker/GlobalMarkers.hpp"

namespace vestige {
namespace core {

Initializer::Initializer() { }

Initializer* Initializer::instance() {
    return &boost::serialization::singleton<core::Initializer>::get_mutable_instance();
}

void Initializer::environment() {
    std::string file = "labseminar8.mov";
    //std::string file = "isuvr/6.mov";
    
    //std::string file = "sort1_3l_5i_s_r.mov";
    //std::string file = "multi1.mov";
    //std::string file = "reverse4_noprog_fail.mov";
    //std::string file = "compress1_3l_4i_s_r.mov";
    
    //std::string file = "remfst1_3l_5i_s_r.mov";
    //std::string file = "join3_3l_4i_s_r.mov";
    //std::string file = "join2_3l_5i_s_r.mov";
    //std::string file = "join1.mov";
    //std::string file = "fail/4.mov";
    //std::string file = "new_markers.mov";
    //std::string file = "reverse3_2l_3i_s_o.mov";
    //std::string file = "reverse2_2l_3i.mov";
    //std::string file = "reverse1_2l_3i.mov";
    //std::string file = "1l_2i_1s.mov";
    //std::string file = "2hiro_1switch.mov";
    
    std::string src = "filesrc location="+core::Parameters::instance()->ROOT()+"/video/"+file+" ! decodebin";
    //std::string src = "v4l2src device=/dev/video0 use-fixed-fps=false";
    
    std::string artoolkit_config = src+" ! ffmpegcolorspace ! capsfilter caps=video/x-raw-rgb,bpp=24 ! identity name=artoolkit ! fakesink";
    setenv("ARTOOLKIT_CONFIG", artoolkit_config.c_str(), 0);
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
    
    if (!_calibration->load(core::Parameters::instance()->ROOT()+"/data/camera_para.dat")) {
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
    marker::GlobalMarkers::instance()->markers_initialize();
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
    environment();
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
