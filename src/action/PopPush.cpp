#include "PopPush.hpp"

namespace vestige {
namespace action {

PopPush::PopPush(state::Node* node, state::Node* from, state::Node* into) : Action(node)
{
    this->_from = from;
    this->_into = into;
}

state::Node* PopPush::from() { return _from; }
state::Node* PopPush::into() { return _into; }

std::string PopPush::text() {
    return "PopPush(Node:" + _node->id() + "|From:" + _from->id() + "|Into:" + _into->id() + ")";
}

}}
