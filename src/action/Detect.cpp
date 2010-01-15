#include "Detect.hpp"

namespace far {
namespace action {

Detect* Detect::instance() { return &boost::serialization::singleton<far::action::Detect>::get_mutable_instance(); }

Detect::Detect()
{
}

Action* Detect::detect() {
	return detect(core::GlobalStorage::instance()->previous_state, core::GlobalStorage::instance()->current_state);
}

Action* Detect::detect(state::State* past, state::State* present) {
	if (! past || ! present) {
		return NULL;
	}
	
	//D(("past::")); past->print();
	//D(("present::")); present->print();
	
	Action::Vector* v = past->diff(present);
	
	// no movements
	if (v->size() == 0) {
		return NULL;
	}
	
	// 2 or more movements implies error
	if (v->size() >= 2) {
		//TODO: modificar todas las acciones para que sean invalidas,
		// probablemente invalid action debe tener un array de items
		BOOST_FOREACH(Action *a, *v) {
			a->alert("INVALID-ACTION");
		}
		return new Invalid(NULL);
	}
	
	// only 1 difference means good movement
	if (v->size() == 1) {
		return (*v)[0];
	}
	
	// this point shouldnt be reached
	return NULL;
}

}}
