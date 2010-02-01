#include "Invalid.hpp"

namespace far {
namespace action {

Invalid::Invalid(state::Node* item) : Action(item)
{
	this->_valid = 0;
}

void Invalid::print() {
	std::cout << "Action [Invalid] | Item: " << item->path() << std::endl;
}

}}
