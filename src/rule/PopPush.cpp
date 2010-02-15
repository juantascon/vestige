#include "PopPush.hpp"

namespace vestige {
namespace rule {

PopPush::PopPush(std::string item, std::string from, std::string into) : Rule(item)
{
	this->from = from;
	this->into = into;
}

int PopPush::valid(action::Action* action) {
	action::PopPush* a = dynamic_cast<action::PopPush*>( action );
	if (!a) { return 0; }
	
	if (a->item_id() != item) { return 0; }
	if (a->from_id() != from) { return 0; }
	if (a->into_id() != into) { return 0; }
	
	return 1;
}

std::string PopPush::text() {
	return "Rule [PopPush] | Item: " + item + " | From: " + from + " | Into: " + into;
}

}}
