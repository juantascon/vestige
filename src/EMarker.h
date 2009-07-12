#ifndef __EMARKER_H
#define __EMARKER_H 1

#include "EIncludes.h"

class EMarker
{
	protected:
		void initMarker(osgART::Tracker* tracker, std::string args);
		void initModel(std::string file);
		
		osgART::Marker* _marker;
		osg::MatrixTransform* _model;
		
	public:
		osgART::Marker* marker();
		osg::MatrixTransform* model();
		
		osg::Vec3 getPos();
		
		EMarker(osgART::Tracker* tracker, osg::NodeCallback* callback, std::string marker_args, std::string model_file); 
};

#endif

