#ifndef __FAR_MARKER_MARKER_HPP
#define __FAR_MARKER_MARKER_HPP

#include "../lib/osg.hpp"
#include "../lib/osgart.hpp"

#include "../core/Debug.hpp"

namespace far {
namespace marker {

class Marker : public osg::NodeCallback
{
	private:
		static const std::string invalid_model_file;
		
	protected:
		void initMarker(std::string args);
		void initModel();
		
		osgART::Marker* _marker;
		osg::MatrixTransform* _model;
		
	public:
		typedef std::vector <Marker*> Vector;
		typedef std::list <Marker*> List;
		
		Marker(std::string marker_args, std::string id);
		
		std::string id;
		
		osgART::Marker* marker();
		osg::MatrixTransform* model();
		void addChild(osg::Node* child);
		void resetModel();
		
		osg::Vec3 position();
		int visible();
		int aligned(Marker* m);
		
		virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
		virtual void update() = 0;
		
		virtual void alert();
};

}}

#endif
