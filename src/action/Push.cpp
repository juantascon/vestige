#include "Push.hpp"

namespace vestige {
namespace action {

Push::Push(state::Node* node, state::Node* into) : Action(node)
{
    this->into = into;
}

std::string Push::into_id() { return into->id(); }

std::string Push::text() {
    return "Push(Node:" + node->id() + "|Into:" + into->id() + ")";
}

}}
