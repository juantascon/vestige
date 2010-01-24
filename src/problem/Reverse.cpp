#include "Reverse.hpp"
#include "../state/GlobalStates.hpp"

namespace far {
namespace problem {

Reverse::Reverse() : Problem()
{
}

state::List* Reverse::get_input(state::State *s) {
	BOOST_FOREACH(state::Node *n, *(s->items)) {
		if (n == s->output) {
			continue;
		}
		else {
			return dynamic_cast<state::List*>(n);
		}
	}
	
	return NULL;
}

state::List* Reverse::get_output(state::State *s) {
	return dynamic_cast<state::List*>(s->output);
}

// the only valid init state is an output empty list
// and an input list with a minimum of 2 elements
int Reverse::valid_init_state(state::State* s) {
	//TODO: poner cada comentario de return 0; en un mensaje de tooltip
	
	//D(("output: %s, mem: 0x%x", s->output->path().c_str(), s->output ));
	
	if ( s->items->size() != 2 ) {
		// only 2 items expected on the board, output and input
		return 0;
	}
	
	state::List* output = get_output(s);
	if (!output) {
		// invalid output type, list expected
		return 0;
	}
	
	if ( output->items->size() != 0 ) {
		// output list is not empty
		return 0;
	}
	
	state::List* input = get_input(s);
	if (!input) {
		// input is not a list
		return 0;
	}
	
	if ( input->items->size() <= 1 ) {
		// input list should have at least 2 items
		return 0;
	}
	
	return 1;
}

int Reverse::valid_final_state(state::State* s) {
	state::List* output = get_output(s);
	
	// check the sizes of both lists
	if ( output->items->size() != _final_state->size() ) {
		return 0;
	}
	
	int fs_index = 0;
	
	BOOST_FOREACH(state::Node *n, *(output->items)) {
		if (n->id != (*_final_state)[fs_index]) {
			return 0;
		}
		fs_index++;
	}
	
	return 1;
}

void Reverse::prepare_final_state() {
	_final_state = new std::vector<std::string>();
	
	state::State* s = state::GlobalStates::instance()->first;
	
	state::List* input = get_input(s);
	
	// store an inverse order list of the input's items ids
	BOOST_REVERSE_FOREACH(state::Node *n, *(input->items)) {
		_final_state->push_back(n->id);
	}
}

void Reverse::prepare_rules() {
	rules = new rule::RuleSet();
	
	state::State* s = state::GlobalStates::instance()->first;
	
	// 1. get the input and output lists
	state::List* input = get_input(s);
	state::List* output = get_output(s);
		
	// 2. generate a reversed order of poppush instructions
	BOOST_REVERSE_FOREACH(state::Node *n, *(input->items)) {
		//D(("node: %s, from: %s, to: %s", n->id.c_str(), input->id.c_str(), output->id.c_str() ));
		rules->add(new rule::PopPush(n->id, input->id, output->id));
	}
}

}}
