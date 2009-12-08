#ifndef __FAR_MARKER_MARKER_HPP
#define __FAR_MARKER_MARKER_HPP

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
		typedef std::vector <Marker*> Vector;
		typedef std::list <Marker*> List;

		Marker(std::string marker_args);
		
		std::string id;
		
		osgART::Marker* marker();
		osg::MatrixTransform* model();
		
		void addChild(osg::Node* child);
		int visible();
		osg::Vec3 position();
		
		int aligned(Marker* m);
		
		virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
		virtual void update() = 0;
};

}}

#endif
