#ifndef __EFACTORY_H
#define __EFACTORY_H 1

#include "EIncludes.hpp"

//TODO: Usar boost singleton
class EFactory
{
	private:
		static EFactory* _instance;
		
	protected:
		osgART::Tracker* tracker;
		osgART::Video* video;
		
		osgART::Calibration* calibration;
		osg::Camera* camera;
		osgViewer::Viewer* viewer;
		osg::Group* root;
		
		EFactory();
		
	public:
		static EFactory* instance();
		
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

#endif
