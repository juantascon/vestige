#ifndef __FAR_INITIALIZER_HPP
#define __FAR_INITIALIZER_HPP

#include "Includes.hpp"

namespace far
{

class Initializer
{
	protected:
		osgART::Tracker* tracker;
		osgART::Video* video;
		osgART::Calibration* calibration;
		osg::Camera* camera;
		osgViewer::Viewer* viewer;
		osg::Group* root;
		Initializer();
				
	public:
		static Initializer *instance();
		void initTracker();
		void initVideo();
		
		void initCalibration();
		void initCamera();
		void initViewer();
		void initRoot();
		void initMarkers();
		
		void initialize();
		int execute();
};

}

#endif
