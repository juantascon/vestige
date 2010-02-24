#ifndef __VESTIGE_PROBLEM_JOIN_HPP
#define __VESTIGE_PROBLEM_JOIN_HPP

#include "ListProblem.hpp"

namespace vestige {
namespace problem {

class Join : public ListProblem
{
	protected:
		state::Node* TMP;
		state::Node* L;
		state::Node* R;
		
	public:
		Join(state::State* s);
		
		virtual rule::RuleSet* create_rules();
};

}}

#endif
