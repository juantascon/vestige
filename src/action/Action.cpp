#include "Action.hpp"

namespace vestige {
namespace action {

Action::Action(state::Node* node)
{
    this->node = node;
    this->valid_rules = 0;
}

std::string Action::node_id() { return node->id(); }

void Action::alert(std::string message) {
    node->alert(message);
}

}}
