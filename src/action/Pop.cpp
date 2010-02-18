#include "Pop.hpp"

namespace vestige {
namespace action {

Pop::Pop(state::Node* item, state::Node* from) : Action(item)
{
	this->from = from;
}

std::string Pop::from_id() { return from->id(); }

std::string Pop::text() {
	return "Action [Pop] | Item: " + item->path() + " | From: " + from->path();
}

}}
