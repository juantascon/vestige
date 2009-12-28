#include "Action.hpp"

namespace far {
namespace action {

Action::Action(state::Node* item)
{
	this->item = item;
}

std::string Action::item_id() { return item->id; }

void Action::alert() {
	item->m->alert();
}

void Action::print() {
	std::cout << "Action [NULL] | Item: " << item->path() << std::endl;
}

}}
