#ifndef __VESTIGE_CORE_SUPERVISOR_HPP
#define __VESTIGE_CORE_SUPERVISOR_HPP

#include "../state/State.hpp"
#include "../action/ActionSet.hpp"
#include "../rule/RuleSet.hpp"
#include "../problem/Types.hpp"

namespace vestige {
namespace core {

class Supervisor
{
	protected:
		Supervisor();
		
		problem::Problem* p;
		
		state::State* previous_state;
		state::State* current_state;
		
	public:
		static Supervisor* instance();
		
		void step();
};

}}

#endif
