#include "Invalid.hpp"

namespace vestige {
namespace action {

Invalid::Invalid(state::Node* node) : Action(node)
{
    this->_valid = 0;
}

std::string Invalid::text() {
    return "Invalid(Node:" + node->path() + ")";
}

}}
