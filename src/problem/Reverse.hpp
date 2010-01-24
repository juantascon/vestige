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
		
		virtual int valid_init_state(state::State* s);
		virtual rule::RuleSet* rules();
};

}}

#endif
