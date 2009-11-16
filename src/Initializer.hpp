#ifndef __FAR_INITIALIZER_HPP
#define __FAR_INITIALIZER_HPP

#include "Includes.hpp"

namespace far
{

//TODO: Usar boost singleton
class Initializer
{
	private:
		static Initializer* _instance;
		
	protected:
		osgART::Tracker* tracker;
		
		
		osgART::Calibration* calibration;
		osg::Camera* camera;
		osgViewer::Viewer* viewer;
		osg::Group* root;
		
		Initializer();
		
	public:
		osgART::Video* video;
		static Initializer* instance();
		
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
