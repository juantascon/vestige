#include "Action.hpp"

namespace vestige {
namespace action {

Action::Action(state::Node* node)
{
    this->node = node;
    this->_valid = 1;
}

std::string Action::node_id() { return node->id(); }
int Action::valid() { return _valid; }

void Action::alert(std::string message) {
    node->alert(message);
}

}}
