#include "Reverse.hpp"

namespace vestige {
namespace problem {

Reverse::Reverse() : Problem()
{
}

int Reverse::initialize(state::State* s) {
	//TODO: poner cada comentario de return 0; en un mensaje de tooltip
	
	/***/
	/* -- Check initial variables -- */
	/***/

	// exactly 2 items variables expected on the board:
	// * L: list with at least 2 elements
	// * R: empty list
	D(("0"));
	_vars = new Variables(s);
	if (!_vars->valid_size(2)) { return 0; }

	D(("1"));
	state::List* L = _vars->next_list_by_size_range(2, (std::numeric_limits<int>::max)());
	// variable L not found, expected list with at least 2 items
	if (!L) { return 0; }

	D(("2"));
	state::List* R = _vars->next_list_by_size_range(0, 0);
	// variable R not found, expected empty list
	if (!R) { return 0;	}
	
	/***/
	/* -- Create Rules -- */
	/***/
	
	_rules = new rule::RuleSet();
	
	// Generate a reversed order of poppush instructions
	BOOST_REVERSE_FOREACH(state::Node *n, *(L->items)) {
		//D(("node: %s, from: %s, to: %s", n->id().c_str(), L->id().c_str(), R->id().c_str() ));
		_rules->add(new rule::PopPush(n->id(), L->id(), R->id()));
	}
	
	/***/
	/* -- Prepare expected return value -- */
	/***/
	
	_return_items_ids = new std::vector<std::string>();
	
	// store an inverse order list of L's items ids
	BOOST_REVERSE_FOREACH(state::Node *n, *(L->items)) {
		_return_items_ids->push_back(n->id());
	}
	
	D(("3"));
	_active = 1;
	return 1;
}

int Reverse::validate_return(state::Node* ret) {
	state::List* l = dynamic_cast<state::List*>(ret);
	if (!l) { return 0; }
	
	return l->check_items_ids(_return_items_ids);
}

}}
