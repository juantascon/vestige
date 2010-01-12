#include "Supervisor.hpp"

namespace far {
namespace core {

Supervisor* Supervisor::instance() { return &boost::serialization::singleton<far::core::Supervisor>::get_mutable_instance(); }

Supervisor::Supervisor()
{
}

void Supervisor::step() {
	state::State *s = state::Capture::instance()->capture();
	if(!s) { return; }
	
	s->create_flat_view();
	
	GlobalStorage::instance()->previous_state = GlobalStorage::instance()->current_state;
	GlobalStorage::instance()->current_state = s;
	
	action::Action *a = action::Detect::instance()->detect();
	if(!a) { return; }
	
	int ret = rule::RuleSet::instance()->apply(a);
	D(("RULESET-STEP:: %i", ret));
	
	if (! ret) {
		a->alert();
	}
}

}}
