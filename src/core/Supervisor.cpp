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
		// save first state
		state::GlobalStates::instance()->first = s;
		// create problem rules
		r = p->rules();
		
		return;
	}
	
	action::Action *a = action::Detect::instance()->detect();
	if (!a) { return; }
	
	int ret = r->apply(a);
	D(("RULESET-APPLY:: %i", ret));
}

}}
