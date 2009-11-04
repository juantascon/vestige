#ifndef __EMARKER_H
#define __EMARKER_H 1

#include "EIncludes.h"
#include "EContainer.h"

class EMarker : public osg::NodeCallback
{
	protected:
		void initMarker(std::string args);
		void initModel(std::string file);
		
		osgART::Marker* _marker;
		osg::MatrixTransform* _model;
		
	public:
		EMarker(std::string marker_args, std::string model_file);
		
		osgART::Marker* marker();
		osg::MatrixTransform* model();
		
		osg::Vec3 position();
		int aligned(EMarker* m);
		
		virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
		virtual void update() = 0;
};

#endif
