#include "Action.hpp"

namespace far {
namespace action {

std::string Action::type_to_string(int type) {
	switch(type) {
		case PopPush: return "PopPush";
		case Pop: return "Pop";
		case Push: return "Push";
		case DiscardBlock: return "DiscardBlock";
		case DiscardList: return "DiscardList";
		case Invalid: return "Invalid";
		case None: return "None";
	}
	
	return "Invalid";
}

Action::Action(state::Node* item, int type)
{
	this->item = item;
	this->type = type;
}

void Action::alert() {
	item->m->alert();
}

void Action::print() {
	std::cout << "Action: " << Action::type_to_string(this->type) << " Item: " << item->path() << std::endl;
}

}}
