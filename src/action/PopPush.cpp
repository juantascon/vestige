#include "PopPush.hpp"

namespace far {
namespace action {

PopPush::PopPush(state::Node* item, state::Node* from, state::Node* into) : Action(item)
{
	this->from = from;
	this->into = into;
}

std::string PopPush::from_id() { return from->id; }
std::string PopPush::into_id() { return into->id; }

std::string PopPush::text() {
	return "Action [PopPush] | Item: " + item->path() + " | From: " + from->path() + " | Into: " + into->path();
}

}}
