#include "GlobalMarkers.hpp"

#include "../lib/osgart.hpp"
#include "../lib/boost.hpp"

namespace vestige {
namespace marker {

GlobalMarkers* GlobalMarkers::instance() {
	return &boost::serialization::singleton<marker::GlobalMarkers>::get_mutable_instance();
}

GlobalMarkers::GlobalMarkers()
{
	_items = new marker::MarkerSet();
	m_return = 0;
	m_switch = 0;
}

void GlobalMarkers::items_add(marker::Marker *m) {
	_items->push_back(m);
}

marker::MarkerSet* GlobalMarkers::items_clone() {
	_items->clone();
}

}}
