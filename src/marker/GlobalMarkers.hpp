#ifndef __VESTIGE_MARKER_GLOBALMARKERS_HPP
#define __VESTIGE_MARKER_GLOBALMARKERS_HPP

#include "Types.hpp"

namespace vestige {
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
