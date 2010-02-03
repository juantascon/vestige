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
		int _active;;
		rule::RuleSet* _rules;
		
	public:
		Problem();
		
		int active();
		rule::RuleSet* rules();
		
		virtual int initialize(state::State* s) = 0;
		virtual int valid_final_state(state::State* s) = 0;
};

}}

#endif
