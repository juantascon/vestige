#ifndef __EFACTORY_H
#define __EFACTORY_H 1

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
		osgART::Video* video;
		
		osgART::Calibration* calibration;
		osg::Camera* camera;
		osgViewer::Viewer* viewer;
		osg::Group* root;
		
		Initializer();
		
	public:
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
