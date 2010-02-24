#ifndef __VESTIGE_PROBLEM_REVERSE_HPP
#define __VESTIGE_PROBLEM_REVERSE_HPP

#include "ListProblem.hpp"

namespace vestige {
namespace problem {

class Reverse : public ListProblem
{
	protected:
		state::Node* L;
		state::Node* R;
		
	public:
		Reverse(state::State* s);
		
		virtual rule::RuleSet* create_rules();
};

}}

#endif
