#include "Discard.hpp"

namespace vestige {
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

std::string Discard::text() {
	return "Rule [Discard] | Item: " + item;
}

}}
