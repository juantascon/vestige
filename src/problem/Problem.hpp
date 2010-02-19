#ifndef __VESTIGE_PROBLEM_PROBLEM_HPP
#define __VESTIGE_PROBLEM_PROBLEM_HPP

#include "../state/State.hpp"
#include "../rule/Types.hpp"
#include "../rule/RuleSet.hpp"

namespace vestige {
namespace problem {

class Problem
{
	protected:
		int _active;;
		rule::RuleSet* _rules;
		
		int validate_return_list(state::Node* ret, std::vector<std::string>* ids);
		
	public:
		Problem();
		
		int active();
		rule::RuleSet* rules();
		
		virtual int validate_return(state::Node* ret) = 0;
		virtual int initialize(state::State* s) = 0;

		
};

}}

#endif
