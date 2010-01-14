#include "Output.hpp"
#include "../core/GlobalStorage.hpp"

namespace far {
namespace marker {

Output::Output(std::string marker_args) : Marker(marker_args, "OUTPUT") {
	value = 0;
}

void Output::update_value() {
	value = 0;
	
	if ( ! this->visible() ) {
		return;
	}
	
	BOOST_FOREACH( marker::Marker* m, *core::GlobalStorage::instance()->sorted_markers_y_axis() ) {
		if (!m->visible()) { continue; }
		
		if ( this->aligned(m) ) {
			value = m;
			return;
		}
	}
}

void Output::update() {
}

}}
