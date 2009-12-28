#include "Discard.hpp"

namespace far {
namespace rule {

Discard::Discard(std::string item) : Rule(item)
{
}

int Discard::valid(action::Action* action) {
	action::Discard* a = dynamic_cast<action::Discard*>( action );
	if (!a) { return 0; }
	
	if (a->item_id() != item) { return 0; }
	
	return 1;
}

void Discard::print() {
	std::cout << "Rule [Discard] | Item: " << item << std::endl;
}

}}
