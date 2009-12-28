#ifndef __FAR_STATE_SUPERVISOR_HPP
#define __FAR_STATE_SUPERVISOR_HPP

#include "State.hpp"

namespace far{
namespace state{

class Supervisor
{
	protected:
		Supervisor();
		
	public:
		static Supervisor* instance();
		
		action::Action* detect_action(State* past, State* present);
};

}}

#endif
