#ifndef __FAR_MARKER_GLOBALMARKERS_HPP
#define __FAR_MARKER_GLOBALMARKERS_HPP

#include "Types.hpp"

namespace far {
namespace marker {

class GlobalMarkers
{
	protected:
		GlobalMarkers();
		
		marker::Marker::Vector _items;
		
	public:
		static GlobalMarkers* instance();
		
		void add(marker::Marker *m);
		marker::Marker::List* sort_y_axis();
		
		marker::Return* m_return;
		marker::Switch* m_switch;
		
};

}}

#endif
