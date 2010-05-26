#include "Push.hpp"

namespace vestige {
namespace action {

Push::Push(state::Node* node, state::Node* into) : Action(node)
{
    this->_into = into;
}

state::Node* Push::into() { return _into; }

std::string Push::text() {
    return "Push(Node:" + _node->id() + "|Into:" + _into->id() + ")";
}

}}
