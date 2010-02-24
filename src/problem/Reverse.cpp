#include "Reverse.hpp"

namespace vestige {
namespace problem {

Reverse::Reverse(state::State* s) : ListProblem()
{
	/***/
	/* -- Check initial variables -- */
	/***/
	
	// exactly 2 items variables expected on the board:
	// * L: list with at least 2 elements
	// * R: empty list
	
	state::NodeSet* lists = s->nodes();
	lists->filter_by_no_parent();
	if (lists->size() != 2) { throw std::runtime_error("2 items are expected on the table"); }
	
	lists->filter_by_type(0, 1);
	if (lists->size() != 2) { throw std::runtime_error("2 lists are expected on the table"); }
	
	L = lists->filter_single_by_size_range(2, (std::numeric_limits<int>::max)());
	if (!L) { throw std::runtime_error("missing 1 list with at least 2 elements"); }
	
	R = lists->filter_single_by_size_range(0, 0);
	if (!R) { throw std::runtime_error("missing 1 empty list"); }

	/***/
	/* -- Prepare return list ids -- */
	/***/
	// store an inverse order list of L's items ids
	BOOST_REVERSE_FOREACH(state::Node *n, *(L->children())) {
		_ids->push_back(n->id());
	}
}

rule::RuleSet* Reverse::create_rules() {
	rule::RuleSet* rules = new rule::RuleSet();

	// Generate a reversed order of poppush instructions
	BOOST_REVERSE_FOREACH(state::Node *n, *(L->children())) {
		D(("node: %s, from: %s, to: %s", n->id().c_str(), L->id().c_str(), R->id().c_str() ));
		rules->add(new rule::PopPush(n->id(), L->id(), R->id()));
	}

	return rules;
}

}}
