#include "Supervisor.hpp"

namespace far{
namespace state{

Supervisor* Supervisor::instance() { return &boost::serialization::singleton<far::state::Supervisor>::get_mutable_instance(); }

Supervisor::Supervisor()
{
}

action::Action* Supervisor::detect_action(State* past, State* present) {
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
}

}}
