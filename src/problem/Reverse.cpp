#include "Reverse.hpp"
#include "../state/GlobalStates.hpp"

namespace far {
namespace problem {

Reverse::Reverse() : Problem()
{
}

// the only valid init state is an output empty list
// and 
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
		
		D(("node: %s, mem: 0x%x", n->path().c_str(), n ));
		
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
	//TODO: implementar este metodo
	
	state::State* s = state::GlobalStates::instance()->first;
	
	rule::RuleSet* ret = new rule::RuleSet();
	//rule::RuleSet::instance()->add(new rule::Pop("b.C", "l.sample1"));
	ret->add(new rule::PopPush("b.C", "l.hiro", "l.sample1"));
	ret->add(new rule::PopPush("b.B", "l.hiro", "l.sample1"));
	ret->add(new rule::PopPush("b.A", "l.hiro", "l.sample1"));
	
	return ret;
}

}}
