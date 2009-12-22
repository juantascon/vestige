#include "Supervisor.hpp"

namespace far{
namespace state{

Supervisor* Supervisor::instance() { return &boost::serialization::singleton<far::state::Supervisor>::get_mutable_instance(); }

Supervisor::Supervisor()
{
}

action::Action* Supervisor::detect_action(State* past, State* present) {
	if (! past || ! present) {
		return new action::Action(NULL, action::Action::None);
	}
	
	//D(("past::")); past->print();
	//D(("present::")); present->print();
	
	action::Action::Vector* v = past->diff(present);
	
	if (v->size() >= 2) {
		BOOST_FOREACH(action::Action *a, *v) {
			a->alert();
		}
		return new action::Action(NULL, action::Action::Invalid);
	}
	else if (v->size() <= 0) {
		return new action::Action(NULL, action::Action::None);
	}
	else {
		return (*v)[0];
	}
}

}}
