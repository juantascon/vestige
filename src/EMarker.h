#ifndef __EMARKER_H
#define __EMARKER_H 1

#include "EIncludes.h"

class EMarker : public osg::NodeCallback
{
	protected:
		void initMarker(osgART::Tracker* tracker, std::string args);
		void initModel(std::string file);
		
		osgART::Marker* _marker;
		osg::MatrixTransform* _model;
		
	public:
		EMarker(osgART::Tracker* tracker, std::string marker_args, std::string model_file);
		
		std::string label;
		
		osgART::Marker* marker();
		osg::MatrixTransform* model();
		
		osg::Vec3 position();
		virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
		virtual void update() = 0;
};

#endif
