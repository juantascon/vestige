#include "Reverse.hpp"
#include "../state/GlobalStates.hpp"

namespace far {
namespace problem {

Reverse::Reverse() : Problem()
{
}

// the only valid init state is an output empty list
// and an input list with a minimum of 2 elements
int Reverse::valid_init_state(state::State* s) {
	//TODO: poner cada comentario de return 0; en un mensaje de tooltip
	
	//D(("output: %s, mem: 0x%x", s->output->path().c_str(), s->output ));
	
	// Output type == List
	if ( ! dynamic_cast<state::List*>(s->output) ) {
		// invalid output type, list expected
		return 0;
	}
	
	// Output items == 0
	if ( (dynamic_cast<state::List*>(s->output))->items->size() != 0 ) {
		// output list is not empty
		return 0;
	}
	
	// Input items == 2   (input and output)
	if ( s->items->size() != 2 ) {
		// only 2 items expected on the board, output and input
		return 0;
	}
	
	BOOST_FOREACH(state::Node *n, *(s->items)) {
		if (n == s->output) { continue; }
		
		//D(("node: %s, mem: 0x%x", n->path().c_str(), n ));
		
		if ( ! dynamic_cast<state::List*>(n) ) {
			// input is not a list
			return 0;
		}
		
		if ( (dynamic_cast<state::List*>(n))->items->size() <= 1 ) {
			// input list should have at least 2 items
			return 0;
		}
	}
	
	return 1;
}

rule::RuleSet* Reverse::rules() {
	//TODO: poner cada comentario de return NULL; en un mensaje de tooltip
	rule::RuleSet* ret = new rule::RuleSet();
	
	state::State* s = state::GlobalStates::instance()->first;
	
	// 1. find the input and output lists
	state::List* input;
	state::List* output;
	
	BOOST_FOREACH(state::Node *n, *(s->items)) {
		if (n == s->output) {
			output = dynamic_cast<state::List*>(n);
		}
		else {
			input = dynamic_cast<state::List*>(n);
		}
	}
	
	if ( !input || !output ) {
		// problem finding input and output lists
		return NULL;
	}
	
	// 2. generate a reversed order of poppush instructions
	BOOST_REVERSE_FOREACH(state::Node *n, *(input->items)) {
		//D(("node: %s, from: %s, to: %s", n->id.c_str(), input->id.c_str(), output->id.c_str() ));
		ret->add(new rule::PopPush(n->id, input->id, output->id));
	}
	
	return ret;
}



}}
