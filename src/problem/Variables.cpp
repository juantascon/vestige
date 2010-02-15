#include "Variables.hpp"

namespace vestige {
namespace problem {


Variables::Variables(state::State* s)
{
	this->s = s;
	_assigned_items = new state::Node::Vector();
}

int Variables::valid_size(int size) {
	return ( s->items->size() == size );
}

state::List* Variables::next_list_by_size_range(int min, int max) {
	BOOST_FOREACH(state::Node *n, *(s->items)) {
		// validate assigned status
		int found = 0;
		BOOST_FOREACH(state::Node *assigned_n, *(_assigned_items)) {
			if (n == assigned_n) { found = 1; break; }
		}
		if (found) { continue; }
		
		// validate data type
		state::List* l = dynamic_cast<state::List*>(n);
		if (!l) { continue; }

		// validate size range
		if (! (l->items->size() >= min && l->items->size() <= max) ) {
			continue;
		}
		
		_assigned_items->push_back(l);
		return l;
	}
	
	return NULL;
}

}}
