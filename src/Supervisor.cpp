#include "Supervisor.hpp"

namespace far{

Supervisor* Supervisor::instance() { return &boost::serialization::singleton<far::Supervisor>::get_mutable_instance(); }

Supervisor::Supervisor()
{
}

action::Action* Supervisor::detect_action(state::State* past, state::State* present) {
	if (! past || ! present) {
		return NULL;
	}
	
	//D(("past::")); past->print();
	//D(("present::")); present->print();
	
	action::Action::Vector* v = past->diff(present);
	
	// no movements
	if (v->size() == 0) {
		return NULL;
	}
	
	// 2 or more movements implies error
	if (v->size() >= 2) {
		//TODO: modificar todas las acciones para que sean invalidas,
		// probablemente invalid action debe tener un array de items
		BOOST_FOREACH(action::Action *a, *v) {
			a->alert();
		}
		return new action::Invalid(NULL);
	}
	
	// only 1 difference means good movement
	if (v->size() == 1) {
		return (*v)[0];
	}
	
	// this point shouldnt be reached
	return NULL;
}

void Supervisor::step() {
	state::Manager* manager = state::Manager::instance();
	
	manager->sync();
	
	if ( manager->previous ) {
		action::Action *a = detect_action(manager->previous, manager->current);
		int ret = rule::RuleSet::instance()->apply(a);
		D(("RULESET-STEP:: %i", ret));
	}
}

}
