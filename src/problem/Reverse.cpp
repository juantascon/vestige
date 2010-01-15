#include "Reverse.hpp"

#include "../core/GlobalStorage.hpp"
#include "../rule/Types.hpp"
#include "../state/Types.hpp"

namespace far {
namespace problem {

Reverse::Reverse() : Problem()
{
}

rule::RuleSet* Reverse::rules() {
	state::State* s = core::GlobalStorage::instance()->first_state;
	
	rule::RuleSet* ret = new rule::RuleSet();
	//rule::RuleSet::instance()->add(new rule::Pop("b.C", "l.sample1"));
	ret->add(new rule::PopPush("b.C", "l.hiro", "l.sample1"));
	ret->add(new rule::PopPush("b.B", "l.hiro", "l.sample1"));
	ret->add(new rule::PopPush("b.A", "l.hiro", "l.sample1"));
	
	return ret;
}

}}
