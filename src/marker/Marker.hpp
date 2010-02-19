#ifndef __VESTIGE_MARKER_MARKER_HPP
#define __VESTIGE_MARKER_MARKER_HPP

#include "../lib/osg.hpp"
#include "../lib/osgart.hpp"

#include "../core/Parameters.hpp"
#include "../core/Debug.hpp"

namespace vestige {
namespace marker {

class Marker : public osg::NodeCallback
{
	protected:
		osgART::Marker* _marker;
		osg::MatrixTransform* _model;
		
		int _valid;
		std::string _id;
		
	public:
		typedef std::vector <Marker*> Vector;
		typedef std::list <Marker*> List;
		typedef std::map <std::string, Marker*> Map;
		
		Marker(std::string marker_args, std::string id);
		
		osgART::Marker* marker();
		osg::MatrixTransform* model();
		std::string id();
		
		void add(osg::Node* child);
		virtual void reset();
		osg::Vec3 position();
		int visible();
		
		int aligned(Marker* m);
		int under(Marker* m);
		int over(Marker* m);
		
		void operator()(osg::Node* node, osg::NodeVisitor* nv);
		
		virtual void paint() = 0;
		virtual void update() = 0;
		virtual void alert(std::string message);
		virtual void set_valid(int valid);
};

}}

#endif
