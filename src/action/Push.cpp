#include "Push.hpp"

namespace vestige {
namespace action {

Push::Push(state::Node* item, state::Node* into) : Action(item)
{
	this->into = into;
}

std::string Push::into_id() { return into->id(); }

std::string Push::text() {
	return "Action [Push] || Item: " + item->path() + " || Into: " + into->path();
}

}}
