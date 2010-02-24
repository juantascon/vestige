#include "Step.hpp"

#include "../marker/GlobalMarkers.hpp"

namespace vestige {
namespace recursion {

Step* Step::instance() {
	return &boost::serialization::singleton<recursion::Step>::get_mutable_instance();
}

Step::Step() {
	previous_state = 0;
	current_state = 0;
}

StatusMessage* Step::step() {
	state::State *s = new state::State();
	s->capture();
	D(( s->text().c_str() ));

	if (s->size() == 0) {
		return new StatusMessage(0, "");
	}
	
	previous_state = current_state;
	current_state = s;
	
	// initialize the problem specification
	if (!p) {
		// Create problem and rules
		try {
			p = new problem::Join(current_state);
			r = p->create_rules();
		}
		catch(std::runtime_error e) {
			return new StatusMessage(0, "Invalid initial state: " + std::string(e.what()));
		}
	}
	
	// check if this state is the valid final state
	if (p->validate_return(current_state->return_value())) {
		return new StatusMessage(1, "Game Over: you win");
	}
	
	action::ActionSet *as = new action::ActionSet();
	as->diff(previous_state, current_state);
	D(( as->text().c_str() ));
	
	// Empty actions are ignored
	action::Action *a = as->single();
	if (!a) { return new StatusMessage(0, ""); }
	
	// Invalid action
	if (!a->valid()) {
		as->alert("invalid movement");
		return new StatusMessage(1, "Invalid Action: too many movements");
	}
	
	// TODO: esto sólo se debe ejecutar en modo supervisado
	if ( !r->apply(a) ) {
		return new StatusMessage(1, "Invalid Action: Step-by-Step wrong movement");
	}
	
	return new StatusMessage(0, "");
}

}}
