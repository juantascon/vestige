#include "Supervisor.hpp"

namespace far {
namespace core {

Supervisor* Supervisor::instance() { return &boost::serialization::singleton<far::core::Supervisor>::get_mutable_instance(); }

Supervisor::Supervisor() {
	p = new problem::Reverse();
}

void Supervisor::step() {
	state::State *s = state::Capture::instance()->capture();
	if (!s) { return; }
	
	state::GlobalStates* gs = state::GlobalStates::instance();
	
	gs->previous = gs->current;
	gs->current = s;
	
	// first state record
	if (!gs->first) {
		// check if the current state is a valid init state
		if (p->valid_init_state(s)) {
			// save first state
			gs->first = s;
			
			// initialize problem information
			p->prepare_rules();
			p->prepare_final_state();
		}
		return;
	}
	
	action::Action *a = action::Detect::instance()->detect(gs->previous, gs->current);
	if (!a) { return; }
	
	// Invalid step end the game
	// TODO: esto sólo se debe ejecutar en modo supervisado
	if ( !a->valid() || !p->rules->apply(a) ) {
		marker::GlobalMarkers::instance()->m_switch->alert("GAME-OVER-LOSE");
		marker::GlobalMarkers::instance()->m_switch->deactivate();
	}
	
	// check if this state is the valid final state
	if (p->valid_final_state(s)) {
		marker::GlobalMarkers::instance()->m_switch->alert("GAME-OVER-WIN");
		marker::GlobalMarkers::instance()->m_switch->deactivate();
	}
}

}}
