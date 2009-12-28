#include "Discard.hpp"

namespace far {
namespace action {

Discard::Discard(state::Node* item) : Action(item)
{
}

void Discard::print() {
	std::cout << "Action [Discard] | Item: " << item->path() << std::endl;
}

}}
