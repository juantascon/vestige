#ifndef __VESTIGE_RECURSION_STEP_HPP
#define __VESTIGE_RECURSION_STEP_HPP

#include "../state/State.hpp"
#include "../action/ActionSet.hpp"
#include "../rule/RuleSet.hpp"
#include "../problem/Types.hpp"

namespace vestige {
namespace recursion {

class Step
{
	protected:
		Step();
		
		problem::Problem* p;
		
		state::State* previous_state;
		state::State* current_state;
		
	public:
		static Step* instance();
		
		void step();
};

}}

#endif
