#include "Pop.hpp"

namespace far {
namespace rule {

Pop::Pop(std::string item, std::string from) : Rule(item)
{
	this->from = from;
}

int Pop::valid(action::Action* action) {
	action::Pop* a = dynamic_cast<action::Pop*>( action );
	if (!a) { return 0; }
	
	if (a->item_id() != item) { return 0; }
	if (a->from_id() != from) { return 0; }
	
	return 1;
}

void Pop::print() {
	std::cout << "Rule [Pop] | Item: " << item << " | From: " << from << std::endl;
}

}}
