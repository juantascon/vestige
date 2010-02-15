#ifndef __VESTIGE_ACTION_DETECT_HPP
#define __VESTIGE_ACTION_DETECT_HPP

#include "Action.hpp"
#include "Invalid.hpp"

#include "../state/State.hpp"

namespace vestige {
namespace action {

class Detect
{
	protected:
		Detect();
		
	public:
		static Detect* instance();
		
		Action* detect(state::State* past, state::State* present);
};

}}

#endif
