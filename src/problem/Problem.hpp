#ifndef __VESTIGE_PROBLEM_PROBLEM_HPP
#define __VESTIGE_PROBLEM_PROBLEM_HPP

#include "../state/State.hpp"
#include "../rule/Types.hpp"
#include "../rule/RuleSet.hpp"

#include <stdexcept>

namespace vestige {
namespace problem {

class Problem
{
	protected:
		Problem();
		
	public:
		virtual rule::RuleSet* create_rules() = 0;
		virtual int validate_return(state::Node* ret) = 0;
};

}}

#endif
