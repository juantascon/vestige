#ifndef __FAR_RULE_RULESET_HPP
#define __FAR_RULE_RULESET_HPP

#include "Rule.hpp"

namespace far{
namespace rule{

class RuleSet
{
	protected:
		RuleSet();
		
		Rule::Vector::iterator current;
		Rule::Vector* items;
		
	public:
		static RuleSet* instance();
		
		void add(Rule* rule);
		int apply(action::Action* action);
};

}}

#endif
