#include "Reverse.hpp"

namespace far {
namespace problem {

Reverse::Reverse() : Problem()
{
}

state::List* Reverse::find_input(state::State* s) {
	BOOST_FOREACH(state::Node *n, *(s->items)) {
		if (n == s->output) {
			continue;
		}
		else {
			state::List* input = dynamic_cast<state::List*>(n);
			if ( input && input->items->size() > 1 ) {
				return input;
			}
		}
	}
	
	return NULL;
}

state::List* Reverse::find_output(state::State* s) {
	state::List* output = dynamic_cast<state::List*>(s->output);
	
	if ( output && output->items->size() == 0 ) {
		return output;
	}

	return NULL;
}

int Reverse::initialize(state::State* s) {
	//TODO: poner cada comentario de return 0; en un mensaje de tooltip
	
	/***/
	/* -- Check initial state -- */
	/***/
	
	// exactly 2 items expected on the board, output and input
	if ( s->items->size() != 2 ) { return 0; }
	
	state::List* output = find_output(s);
	// output list not found, expected empty list
	if (!output) { return 0; }
	
	state::List* input = find_input(s);
	// input list not found, expected list with at least 2 items
	if (!input) { return 0;	}
	
	/***/
	/* -- Create Rules -- */
	/***/
	
	_rules = new rule::RuleSet();
		
	// Generate a reversed order of poppush instructions
	BOOST_REVERSE_FOREACH(state::Node *n, *(input->items)) {
		//D(("node: %s, from: %s, to: %s", n->id.c_str(), input->id.c_str(), output->id.c_str() ));
		_rules->add(new rule::PopPush(n->id, input->id, output->id));
	}
	
	/***/
	/* -- Prepare final state -- */
	/***/
	
	_final_output = new std::vector<std::string>();
	
	// store an inverse order list of the input's items ids
	BOOST_REVERSE_FOREACH(state::Node *n, *(input->items)) {
		_final_output->push_back(n->id);
	}

	_active = 1;
	return 1;
}

int Reverse::valid_final_state(state::State* s) {
	state::List* output = dynamic_cast<state::List*>(s->output);
	
	// check the sizes of both lists
	if ( output->items->size() != _final_output->size() ) {
		return 0;
	}
	
	int fs_index = 0;
	
	BOOST_FOREACH(state::Node *n, *(output->items)) {
		if (n->id != (*_final_output)[fs_index]) {
			return 0;
		}
		fs_index++;
	}
	
	return 1;
}

}}
