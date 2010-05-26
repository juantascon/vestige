#include "Discard.hpp"

namespace vestige {
namespace action {

Discard::Discard(state::Node* node) : Action(node)
{
}

std::string Discard::text() {
    return "Discard(Node:" + _node->id() + ")";
}

}}
