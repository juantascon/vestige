#include "RuleSet.hpp"

namespace vestige {
namespace rule {

RuleSet::RuleSet()
{
	items = new Rule::Vector();
	current = items->begin();
}

void RuleSet::add(Rule* rule) {
	items->push_back(rule);
	current = items->begin();
}

int RuleSet::apply(action::Action* action) {
	if ( (*current)->valid(action) ) {
		++current;
		return 1;
	}
	
	action->alert("APPLY-RULE");
	return 0;
}

}}
