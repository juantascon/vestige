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
	
	p = new problem::Reverse();
	//p = new problem::Join();
}

Step::Status Step::step() {
	state::State *s = new state::State();
	s->capture();
	D(( s->text().c_str() ));
	
	// has the problem been activated
	if (!p->active()) {
		// Check initial state, create rules and prepare final state
		if (!p->initialize(s)) {
			return INVALID_INIT_STATE;
		}
	}
	
	previous_state = current_state;
	current_state = s;
	
	action::ActionSet *as = new action::ActionSet();
	as->diff(previous_state, current_state);
	D(( as->text().c_str() ));

	// Empty actions are ignored
	action::Action *a = as->single();
	if (!a) { return GOOD_EMPTY; }
	
	// Invalid action
	if (!a->valid()) {
		as->alert("invalid movement");
		return FAIL_INVALID;
	}
	
	// TODO: esto sólo se debe ejecutar en modo supervisado
	if ( !p->rules()->apply(a) ) {
		return FAIL_RULE;
	}
	
	// check if this state is the valid final state
	if (p->validate_return(current_state->return_value())) {
		return WON;
	}
	
	return GOOD_NORMAL;
}

}}
