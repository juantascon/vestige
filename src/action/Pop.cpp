#include "Pop.hpp"

namespace vestige {
namespace action {

Pop::Pop(state::Node* node, state::Node* from) : Action(node)
{
    this->from = from;
}

std::string Pop::from_id() { return from->id(); }

std::string Pop::text() {
    return "Pop(Node:" + node->id() + "|From:" + from->id() + ")";
}

}}
