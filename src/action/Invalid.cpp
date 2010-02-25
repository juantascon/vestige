#include "Invalid.hpp"

namespace vestige {
namespace action {

Invalid::Invalid(state::Node* item) : Action(item)
{
    this->_valid = 0;
}

std::string Invalid::text() {
    return "Action [Invalid] | Item: " + item->path();
}

}}
