#ifndef __FAR_PROBLEM_PROBLEM_HPP
#define __FAR_PROBLEM_PROBLEM_HPP

#include "Variables.hpp"

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
		Variables* _vars;
		
	public:
		Problem();
		
		int active();
		rule::RuleSet* rules();
		
		virtual int validate_return(state::Node* ret) = 0;
		virtual int initialize(state::State* s) = 0;
};

}}

#endif
