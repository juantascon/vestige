#ifndef __VESTIGE_CORE_INITIALIZER_HPP
#define __VESTIGE_CORE_INITIALIZER_HPP

#include "../lib/osg.hpp"
#include "../lib/osgart.hpp"

#include "Parameters.hpp"

#include <fstream>
#include <stdexcept>

namespace vestige {
namespace core {

class Initializer
{
    protected:
        osgART::Tracker* _tracker;
        osgART::Video* _video;
        osgART::Calibration* _calibration;
        osg::Camera* _camera;
        osgViewer::Viewer* _viewer;
        osg::Group* _root;
        
        void environment();
        void video();
        void tracker();
        void calibration();
        void markers();
        void camera();
        void viewer();
        void root();
        
        Initializer();
        
    public:
        static Initializer *instance();
        
        void initialize();
        int execute();
};

}}

#endif
