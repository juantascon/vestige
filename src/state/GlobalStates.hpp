#ifndef __FAR_STATE_GLOBALSTATES_HPP
#define __FAR_STATE_GLOBALSTATES_HPP

#include "State.hpp"

namespace far {
namespace state {

class GlobalStates
{
	protected:
		GlobalStates();
		
	public:
		static GlobalStates* instance();
		
		state::State* current;
		state::State* previous;
		state::State* first;
};

}}

#endif
