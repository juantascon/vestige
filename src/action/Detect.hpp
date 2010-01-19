#ifndef __FAR_ACTION_DETECT_HPP
#define __FAR_ACTION_DETECT_HPP

#include "Action.hpp"
#include "Invalid.hpp"

#include "../state/State.hpp"

namespace far {
namespace action {

class Detect
{
	protected:
		Detect();
		
		Action* detect(state::State* past, state::State* present);
				
	public:
		static Detect* instance();
		
		Action* detect();
};

}}

#endif
