#ifndef __FAR_RULE_RULESET_HPP
#define __FAR_RULE_RULESET_HPP

#include "RuleSet.hpp"
#include "Rules.hpp"

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
		int step(action::Action* action);
};

}}

#endif