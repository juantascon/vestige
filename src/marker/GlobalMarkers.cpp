#include "GlobalMarkers.hpp"

#include "../lib/osgart.hpp"
#include "../lib/boost.hpp"

namespace far {
namespace marker {

GlobalMarkers* GlobalMarkers::instance() {
	return &boost::serialization::singleton<far::marker::GlobalMarkers>::get_mutable_instance();
}

GlobalMarkers::GlobalMarkers() : _items()
{
	m_output = 0;
	m_switch = 0;
}

void GlobalMarkers::add(marker::Marker *m) {
	_items.push_back(m);
}

marker::Marker::List* GlobalMarkers::sort_y_axis() {
	//D(("BEGIN"));
	
	marker::Marker::List* ret = new marker::Marker::List();
	
	BOOST_FOREACH( marker::Marker* m, _items ) {
		//D((":: check marker: "));
		
		if (!m->visible()) { continue; }
		
		int inserted = 0;
		
		for (marker::Marker::List::iterator it = ret->begin(); it != ret->end(); ++it) {
			//D(( (*it)->value ));
			
			if ( (*it)->position().y() > m->position().y() ) {
				ret->insert( it, m );
				inserted = 1;
				break;
			}
		}
		
		if (!inserted) { ret->push_back( m ); }
	}
	
	/*for (marker::Marker::List::iterator it = ret->begin(); it != ret->end(); it++) {
		D(("ret: %s ref: %x", (*it)->id.c_str(), *it));
	}*/
	
	//D(( "END" ));
	
	return ret;
}

}}
