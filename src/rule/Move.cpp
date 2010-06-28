#include "Move.hpp"

namespace vestige {
namespace rule {

Move::Move(std::string node)
{
    this->_node = node;
}

int Move::valid(action::Action* action) {
    return 0;
}

}}
