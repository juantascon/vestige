#ifndef __FAR_MARKER_LIST_HPP
#define __FAR_MARKER_LIST_HPP

#include "Marker.hpp"
#include "../core/DrawHelper.hpp"

namespace far {
namespace marker {

class List : public Marker
{
	protected:
		osg::Node* background(int valid);
		
	public:
		List (std::string marker_args, std::string id);
		
		virtual void update();
};

}}

#endif
