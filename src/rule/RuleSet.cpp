#include "RuleSet.hpp"

namespace far{
namespace rule{

RuleSet* RuleSet::instance() { return &boost::serialization::singleton<far::rule::RuleSet>::get_mutable_instance(); }

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
	
	return 0;
}

}}
