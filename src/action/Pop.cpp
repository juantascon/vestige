#include "Pop.hpp"

namespace vestige {
namespace action {

Pop::Pop(state::Node* node, state::Node* from) : Action(node)
{
    this->_from = from;
}

state::Node* Pop::from() { return _from; }

std::string Pop::text() {
    return "Pop(Node:" + _node->id() + "|From:" + _from->id() + ")";
}

}}
