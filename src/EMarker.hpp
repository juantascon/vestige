#ifndef __EMARKER_H
#define __EMARKER_H 1

#include "EIncludes.hpp"
#include "EMarkerContainer.hpp"

class EMarker : public osg::NodeCallback
{
	protected:
		void initMarker(std::string args);
		void initModel();
		
		osgART::Marker* _marker;
		osg::MatrixTransform* _model;
		
	public:
		EMarker(std::string marker_args);
		
		osgART::Marker* marker();
		osg::MatrixTransform* model();
		void addChild(osg::Node* child);
		
		osg::Vec3 position();
		int aligned(EMarker* m);
		
		virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
		virtual void update() = 0;
};

#endif
