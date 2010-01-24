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
		
		virtual int valid_init_state(state::State* s) = 0;
		virtual rule::RuleSet* rules() = 0;
};

}}

#endif
