#ifndef __FAR_PROBLEM_REVERSE_HPP
#define __FAR_PROBLEM_REVERSE_HPP

#include "Problem.hpp"

namespace far {
namespace problem {

class Reverse : public Problem
{
	protected:
		
	public:
		Reverse();
		virtual rule::RuleSet* rules();
};

}}

#endif
