#include "PopPush.hpp"

namespace vestige {
namespace action {

PopPush::PopPush(state::Node* node, state::Node* from, state::Node* into) : Action(node)
{
    this->from = from;
    this->into = into;
}

std::string PopPush::from_id() { return from->id(); }
std::string PopPush::into_id() { return into->id(); }

std::string PopPush::text() {
    return "PopPush(Node:" + node->path() + "|From:" + from->path() + "|Into:" + into->path() + ")";
}

}}
