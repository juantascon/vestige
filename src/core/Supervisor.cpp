#include "Supervisor.hpp"

namespace far {
namespace core {

Supervisor* Supervisor::instance() {
	return &boost::serialization::singleton<far::core::Supervisor>::get_mutable_instance();
}

Supervisor::Supervisor() {
	previous_state = 0;
	current_state = 0;
	
	p = new problem::Reverse();
	//p = new problem::Join();
}

void Supervisor::step() {
	state::State *s = state::Capture::instance()->capture();
	if (!s) { return; }
	
	// has been the problem activated
	if (!p->active()) {
		// Check initial state, create rules and prepare final state
		if (!p->initialize(s)) {
			marker::GlobalMarkers::instance()->m_switch->alert("INVALID-INIT-STATE");
			return;
		}
	}
	
	previous_state = current_state;
	current_state = s;
	
	action::Action *a = action::Detect::instance()->detect(previous_state, current_state);
	if (!a) {
		marker::GlobalMarkers::instance()->m_switch->alert("EMPTY-ACTION");
		return;
	}
	
	// Invalid step end the game
	// TODO: esto sólo se debe ejecutar en modo supervisado
	if ( !a->valid() || !p->rules()->apply(a) ) {
		marker::GlobalMarkers::instance()->m_switch->alert("GAME-OVER-LOSE");
		marker::GlobalMarkers::instance()->m_switch->deactivate();
	}
	
	// check if this state is the valid final state
	if (p->validate_return(s->output)) {
		marker::GlobalMarkers::instance()->m_switch->alert("GAME-OVER-WIN");
		marker::GlobalMarkers::instance()->m_switch->deactivate();
	}
}

}}
