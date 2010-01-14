#include "GlobalStorage.hpp"

namespace far {
namespace core {

GlobalStorage* GlobalStorage::instance() { return &boost::serialization::singleton<far::core::GlobalStorage>::get_mutable_instance(); }

GlobalStorage::GlobalStorage() : markers()
{
}

void GlobalStorage::add_marker(marker::Marker *m) {
	markers.push_back(m);
}

marker::Marker::List* GlobalStorage::sorted_markers_y_axis() {
	//D(("BEGIN"));
	
	marker::Marker::List* ret = new marker::Marker::List();
	
	BOOST_FOREACH( marker::Marker* m, markers ) {
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
