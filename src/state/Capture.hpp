#ifndef __FAR_STATE_CAPTURE_HPP
#define __FAR_STATE_CAPTURE_HPP

#include "Types.hpp"
#include "../marker/Types.hpp"

namespace far {
namespace state {

class Capture
{
	protected:
		Capture();
		
		marker::Marker::List* tmp_markers;
		state::State* tmp_state;
		
		Node* do_block(marker::Marker* m);
		Node* do_list(marker::Marker* m);
		
	public:
		static Capture* instance();
		
		State* capture();
};

}}

#endif
