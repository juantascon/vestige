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

void Step::step() {
	state::State *s = new state::State();
	s->capture();
	D(( s->text().c_str() ));
	
	// has the problem been activated
	if (!p->active()) {
		// Check initial state, create rules and prepare final state
		if (!p->initialize(s)) {
			// TODO: mostrar esto mejor
			//marker::GlobalMarkers::instance()->m_switch->alert("INVALID-INIT-STATE");
			return;
		}
	}
	
	previous_state = current_state;
	current_state = s;
	
	action::ActionSet *as = new action::ActionSet();
	as->diff(previous_state, current_state);
	D(( as->text().c_str() ));
	
	action::Action *a = as->single();
	if (!a) {
		// TODO: mostrar esto mejor
		//marker::GlobalMarkers::instance()->m_switch->alert("EMPTY-ACTION");
		return;
	}
	
	// Invalid step end the game
	// TODO: esto sólo se debe ejecutar en modo supervisado
	if ( !a->valid() || !p->rules()->apply(a) ) {
		marker::GlobalMarkers::instance()->m_switch->alert("GAME-OVER-LOSE");
		marker::GlobalMarkers::instance()->m_switch->set_valid(0);
	}
	
	// check if this state is the valid final state
	if (p->validate_return(s->return_value())) {
		marker::GlobalMarkers::instance()->m_switch->alert("GAME-OVER-WIN");
		marker::GlobalMarkers::instance()->m_switch->set_valid(0);
	}
}

}}
