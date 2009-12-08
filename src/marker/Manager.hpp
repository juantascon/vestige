#ifndef __FAR_MARKER_MANAGER_HPP
#define __FAR_MARKER_MANAGER_HPP

#include "../Includes.hpp"
#include "Marker.hpp"

namespace far {
namespace marker {

class Manager : public marker::Marker::Vector
{
	protected:
		Manager();
		
	public:
		static Manager* instance();
		
		osgART::Tracker* tracker;
		osg::Camera* camera;
		
		void add(marker::Marker *m);
};

}}

#endif
