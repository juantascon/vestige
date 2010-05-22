#include "Create.hpp"

namespace vestige {
namespace action {

Create::Create(state::Node* node) : Action(node)
{
}

std::string Create::text() {
    return "Create(Node:" + node->id() + ")";
}

}}
