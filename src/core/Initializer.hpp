#ifndef __FAR_CORE_INITIALIZER_HPP
#define __FAR_CORE_INITIALIZER_HPP

#include "../Includes.hpp"
#include "GlobalStorage.hpp"

#include "../marker/Types.hpp"
#include "../rule/Types.hpp"

#include "../rule/RuleSet.hpp"

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

}}

#endif
