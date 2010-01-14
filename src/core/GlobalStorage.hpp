#ifndef __FAR_CORE_GLOBALSTORAGE_HPP
#define __FAR_CORE_GLOBALSTORAGE_HPP

#include "../lib/osgart.hpp"

#include "../marker/Marker.hpp"
#include "../state/State.hpp"

namespace far {
namespace core {

class GlobalStorage
{
	protected:
		GlobalStorage();
		
	public:
		static GlobalStorage* instance();
		
		marker::Marker::Vector markers;
		void add_marker(marker::Marker *m);
		marker::Marker::List* sorted_markers_y_axis();
		
		state::State* current_state;
		state::State* previous_state;
		
		osgART::Tracker* tracker;
		osg::Camera* camera;
		
};

}}

#endif
