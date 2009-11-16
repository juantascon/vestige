#ifndef __EMARKER_H
#define __EMARKER_H

#include "../Includes.hpp"

namespace far {
namespace marker {

class Marker : public osg::NodeCallback
{
	protected:
		void initMarker(std::string args);
		void initModel();
		
		osgART::Marker* _marker;
		osg::MatrixTransform* _model;
		
	public:
		Marker(std::string marker_args);
		
		int processed;
		
		osgART::Marker* marker();
		osg::MatrixTransform* model();
		void addChild(osg::Node* child);
		
		osg::Vec3 position();
		int aligned(Marker* m);
		
		virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
		virtual void update() = 0;
};

typedef std::vector <Marker*> Vector;

}}

#endif
