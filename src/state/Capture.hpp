#ifndef __VESTIGE_STATE_CAPTURE_HPP
#define __VESTIGE_STATE_CAPTURE_HPP

#include "Types.hpp"
#include "../marker/Types.hpp"
#include "../marker/MarkerSet.hpp"

namespace vestige {
namespace state {

class Capture
{
	protected:
		Capture();
		
		marker::MarkerSet* _markers;
		state::State* _state;
		
		Node* do_block(marker::Marker* m);
		Node* do_list(marker::Marker* m);
		
	public:
		static Capture* instance();
		
		State* capture();
};

}}

#endif
