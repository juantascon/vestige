#include "Pop.hpp"

namespace vestige {
namespace rule {

Pop::Pop(std::string item, std::string from) : Rule(item)
{
	this->from = from;
}

int Pop::valid(action::Action* action) {
    action::Pop* a = dynamic_cast<action::Pop*>( action );
	
	if (!a) { return 0; }
	
	if (a->item_id() != from) { return 0; }
	
	return 1;
}

std::string Pop::text() {
	return "Rule [Pop] | Item: " + item + " | From: " + from;
}

}}
