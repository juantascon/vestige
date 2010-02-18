#ifndef __VESTIGE_MARKER_GLOBALMARKERS_HPP
#define __VESTIGE_MARKER_GLOBALMARKERS_HPP

#include "Types.hpp"
#include "MarkerSet.hpp"

namespace vestige {
namespace marker {

class GlobalMarkers
{
	protected:
		GlobalMarkers();
		
		marker::MarkerSet* _items;
		
	public:
		static GlobalMarkers* instance();
		
		void items_add(marker::Marker *m);
		marker::MarkerSet* items_clone();

		marker::MarkerSet* sort_y_axis();
		
		marker::Return* m_return;
		marker::Switch* m_switch;
};

}}

#endif
