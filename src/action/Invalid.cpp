#include "Invalid.hpp"

namespace far {
namespace action {

Invalid::Invalid(state::Node* item) : Action(item)
{
}

void Invalid::print() {
	std::cout << "Action [Invalid] | Item: " << item->path() << std::endl;
}

}}
