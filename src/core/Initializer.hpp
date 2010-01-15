#ifndef __FAR_CORE_INITIALIZER_HPP
#define __FAR_CORE_INITIALIZER_HPP

#include "../lib/osgart.hpp"

#include "GlobalStorage.hpp"
#include "../marker/Types.hpp"
#include "../problem/Types.hpp"

namespace far {
namespace core {

class Initializer
{
	protected:
		osgART::Tracker* tracker;
		osgART::Video* video;
		osgART::Calibration* calibration;
		osg::Camera* camera;
		osgViewer::Viewer* viewer;
		osg::Group* root;
		
		void initVideo();
		void initTracker();
		void initCalibration();
		void initMarkers();
		void initProblem();
		void initCamera();
		void initViewer();
		void initRoot();
		
		Initializer();
		
	public:
		static Initializer *instance();
		
		void initialize();
		int execute();
};

}}

#endif
