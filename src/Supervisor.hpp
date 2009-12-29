#ifndef __FAR_SUPERVISOR_HPP
#define __FAR_SUPERVISOR_HPP

#include "state/Manager.hpp"

namespace far{

class Supervisor
{
	protected:
		Supervisor();
		
	public:
		static Supervisor* instance();
		
		action::Action* detect_action(state::State* past, state::State* present);
		void step();
};

}

#endif
