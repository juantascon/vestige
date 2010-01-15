#include "Action.hpp"

namespace far {
namespace action {

Action::Action(state::Node* item)
{
	this->item = item;
}

std::string Action::item_id() { return item->id; }

void Action::alert(std::string message) {
	item->m->alert(message);
}

void Action::print() {
	std::cout << "Action [NULL] | Item: " << item->path() << std::endl;
}

}}
