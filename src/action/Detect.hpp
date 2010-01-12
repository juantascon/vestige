#ifndef __FAR_ACTION_DETECT_HPP
#define __FAR_ACTION_DETECT_HPP

#include "Action.hpp"
#include "Invalid.hpp"

#include "../state/State.hpp"

#include "../core/GlobalStorage.hpp"

namespace far {
namespace action {

class Detect
{
	protected:
		Detect();
				
	public:
		static Detect* instance();
		
		Action* detect(state::State* past, state::State* present);
		Action* detect();
};

}}

#endif
