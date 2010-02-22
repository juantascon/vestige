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
		
		typedef enum Status {
			INVALID_INIT_STATE = -1,
			GOOD_NORMAL = 1,
			GOOD_EMPTY = 2,
			FAIL_INVALID = -1,
			FAIL_RULE = -2,
			WON = 0
		} Status;
		
		Status step();
};

}}

#endif
