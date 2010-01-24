#ifndef __FAR_PROBLEM_PROBLEM_HPP
#define __FAR_PROBLEM_PROBLEM_HPP

#include "../state/Types.hpp"
#include "../rule/Types.hpp"

#include "../rule/RuleSet.hpp"

namespace far {
namespace problem {

class Problem
{
	protected:
		
	public:
		Problem();
		
		rule::RuleSet* rules;
		
		virtual int valid_init_state(state::State* s) = 0;
		virtual int valid_final_state(state::State* s) = 0;
		
		virtual void prepare_final_state() = 0;
		virtual void prepare_rules() = 0;
};

}}

#endif
