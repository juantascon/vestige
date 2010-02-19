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
	
	state::NodeSet* _lists = s->nodes();
	_lists->filter_by_no_parent();
	
	// exactly 2 items variables expected on the board:
	// * L: list with at least 2 elements
	// * R: empty list
	if (_lists->size() != 2) { return 0; }
	
	_lists->filter_by_type(0, 1);
	state::Node* L = _lists->filter_single_by_size_range(2, (std::numeric_limits<int>::max)());
	// variable L not found, expected list with at least 2 items
	if (!L) { return 0; }
	
	state::Node* R = _lists->filter_single_by_size_range(0, 0);
	// variable R not found, expected empty list
	if (!R) { return 0;	}
	
	/***/
	/* -- Create Rules -- */
	/***/
	
	_rules = new rule::RuleSet();
	
	// Generate a reversed order of poppush instructions
	BOOST_REVERSE_FOREACH(state::Node *n, *(L->children())) {
		D(("node: %s, from: %s, to: %s", n->id().c_str(), L->id().c_str(), R->id().c_str() ));
		_rules->add(new rule::PopPush(n->id(), L->id(), R->id()));
	}
	
	/***/
	/* -- Prepare expected return value -- */
	/***/
	
	_return_items_ids = new std::vector<std::string>();
	
	// store an inverse order list of L's items ids
	BOOST_REVERSE_FOREACH(state::Node *n, *(L->children())) {
		_return_items_ids->push_back(n->id());
	}
	
	_active = 1;
	return 1;
}

int Reverse::validate_return(state::Node* ret) {
	return this->validate_return_list(ret, _return_items_ids);
}

}}
