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
	
	GlobalStorage::instance()->previous_state = GlobalStorage::instance()->current_state;
	GlobalStorage::instance()->current_state = s;
	
	if (!GlobalStorage::instance()->first_state) {
		// save first state
		GlobalStorage::instance()->first_state = s;
		// create problem rules
		GlobalStorage::instance()->rules = GlobalStorage::instance()->current_problem->rules();
		
		return;
	}
	
	action::Action *a = action::Detect::instance()->detect();
	if(!a) { return; }
	
	int ret = GlobalStorage::instance()->rules->apply(a);
	D(("RULESET-APPLY:: %i", ret));
}

}}
