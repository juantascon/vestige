#include "Action.hpp"

namespace vestige {
namespace action {

Action::Action(state::Node* node)
{
    this->_node = node;
    this->valid_rules = 0;
    this->valid_logic = 0;
}

state::Node* Action::node() { return _node; }

void Action::alert(std::string message) {
    _node->alert(message);
}

}}
