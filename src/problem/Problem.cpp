#include "Problem.hpp"

namespace vestige {
namespace problem {

Problem::Problem() {
	_active = 0;
	_rules = 0;
}

int Problem::active() { return _active; }
rule::RuleSet* Problem::rules() { return _rules; }
	
int Problem::validate_return_list(state::Node* ret, std::vector<std::string>* ids) {
	if ( ! dynamic_cast<marker::List*>(ret->marker()) ) {
		return 0;
	}
	
	// sizes must match
	if ( ret->children()->size() != ids->size() ) {
		return 0;
	}
	
	int index = 0;
	BOOST_FOREACH(state::Node* n, *(ret->children())) {
		if (n->id() != (*ids)[index]) {
			return 0;
		}
		index++;
	}
	
	return 1;
}

}}
