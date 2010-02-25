#include "Action.hpp"

namespace vestige {
namespace action {

Action::Action(state::Node* item)
{
    this->item = item;
    this->_valid = 1;
}

std::string Action::item_id() { return item->id(); }
int Action::valid() { return _valid; }

void Action::alert(std::string message) {
    item->alert(message);
}

}}
