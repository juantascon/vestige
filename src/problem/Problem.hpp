#ifndef __FAR_PROBLEM_PROBLEM_HPP
#define __FAR_PROBLEM_PROBLEM_HPP

#include "../rule/RuleSet.hpp"

namespace far {
namespace problem {

class Problem
{
	protected:
		
	public:
		Problem();
		
		virtual rule::RuleSet* rules() = 0;
};

}}

#endif
