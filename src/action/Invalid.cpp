#include "Invalid.hpp"

namespace vestige {
namespace action {

Invalid::Invalid(state::Node* node) : Action(node)
{
}

std::string Invalid::text() {
    return "Invalid(Node:" + _node->path() + ")";
}

}}
