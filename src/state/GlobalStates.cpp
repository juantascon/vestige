#include "GlobalStates.hpp"

namespace far {
namespace state {

GlobalStates* GlobalStates::instance() {
	return &boost::serialization::singleton<far::state::GlobalStates>::get_mutable_instance();
}

GlobalStates::GlobalStates()
{
	current = 0;
	previous = 0;
	first = 0;
}

}}
