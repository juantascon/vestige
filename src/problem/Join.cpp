#include "Join.hpp"

namespace vestige {
namespace problem {

Join::Join() : Problem()
{
}

int Join::initialize(state::State* s) {
	//TODO: poner cada comentario de return 0; en un mensaje de tooltip
	
	/***/
	/* -- Check initial state -- */
	/***/
	
	// exactly 3 items expected on the board:
	// * TMP: empty list
	// * L: list with at least 2 elements
	// * R: list with at least 2 elements
	_vars = new Variables(s);
	if (!_vars->valid_size(3)) { return 0; }
	
	state::List* TMP = _vars->next_list_by_size_range(0, 0);
	// variable TMP not found, expected empty list
	if (!TMP) { return 0; }
	
	state::List* R = _vars->next_list_by_size_range(2, (std::numeric_limits<int>::max)());
	// variable R not found, expected list with at least 2 elements
	if (!R) { return 0; }
	
	state::List* L = _vars->next_list_by_size_range(2, (std::numeric_limits<int>::max)());
	// variable L not found, expected list with at least 2 elements
	if (!L) { return 0; }
	
	/***/
	/* -- Create Rules -- */
	/***/
	
	_rules = new rule::RuleSet();
	
	// 1. move all the elements from L to TMP
	BOOST_REVERSE_FOREACH(state::Node *n, *(L->items)) {
		//D(("node: %s, from: %s, to: %s", n->id.c_str(), L->id.c_str(), TMP->id.c_str() ));
		_rules->add(new rule::PopPush(n->id, L->id, TMP->id));
	}
	
	// 2. move the same elements from tmp to R
	BOOST_FOREACH(state::Node *n, *(L->items)) {
		//D(("node: %s, from: %s, to: %s", n->id.c_str(), TMP->id.c_str(), R->id.c_str() ));
		_rules->add(new rule::PopPush(n->id, TMP->id, R->id));
	}
	
	/***/
	/* -- Prepare final state -- */
	/***/
	
	_return_items_ids = new std::vector<std::string>();
	
	// items from R plus items from L
	BOOST_FOREACH(state::Node *n, *(R->items)) {
		_return_items_ids->push_back(n->id);
	}
	BOOST_FOREACH(state::Node *n, *(L->items)) {
		_return_items_ids->push_back(n->id);
	}
	
	_active = 1;
	return 1;
}

int Join::validate_return(state::Node* ret) {
	state::List* l = dynamic_cast<state::List*>(ret);
	if (!l) { return 0; }
	
	return l->check_items_ids(_return_items_ids);
}

}}
