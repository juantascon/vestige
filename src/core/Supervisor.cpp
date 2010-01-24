#include "Supervisor.hpp"

namespace far {
namespace core {

Supervisor* Supervisor::instance() { return &boost::serialization::singleton<far::core::Supervisor>::get_mutable_instance(); }

Supervisor::Supervisor()
{
	p = new problem::Reverse();
}

void Supervisor::step() {
	state::State *s = state::Capture::instance()->capture();
	if (!s) { return; }
	
	state::GlobalStates* gs = state::GlobalStates::instance();
	
	gs->previous = gs->current;
	gs->current = s;
	
	if (!gs->first) {
		// check if the current state is a valid init state
		if (p->valid_init_state(s)) {
			// save first state
			gs->first = s;
			
			// create problem rules
			r = p->rules();
		}
	}
	else {
		action::Action *a = action::Detect::instance()->detect(gs->previous, gs->current);
		if (!a) { return; }
		
		int ret = r->apply(a);
		D(("RULESET-APPLY:: %i", ret));
	}
}

}}
