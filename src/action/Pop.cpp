#include "Pop.hpp"

namespace far {
namespace action {

Pop::Pop(state::Node* item, state::Node* from) : Action(item)
{
	this->from = from;
}

std::string Pop::from_id() { return from->id; }

void Pop::print() {
	std::cout << "Action [Pop] | Item: " << item->path() << " | From: " << from->path() << std::endl;
}

}}
