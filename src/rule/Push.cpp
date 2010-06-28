#include "Push.hpp"

namespace vestige {
namespace rule {

Push::Push(std::string node, std::string into) : Move(node)
{
    this->_into = into;
}

int Push::valid(action::Action* action) {
    action::Push* a = dynamic_cast<action::Push*>( action );
    if (!a) { return 0; }
    
    if (a->node()->id() != _node) { return 0; }
    if (a->into()->id() != _into) { return 0; }
    
    return 1;
}

std::string Push::text() {
    return "Push(Node:" + _node + "|Into:" + _into + ")";
}

}}

