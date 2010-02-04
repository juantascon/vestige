#include "Problem.hpp"

namespace far {
namespace problem {

Problem::Problem() {
	_active = 0;
	_rules = 0;
	_vars = 0;
}

int Problem::active() { return _active; }
rule::RuleSet* Problem::rules() { return _rules; }

}}
