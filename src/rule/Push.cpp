#include "Push.hpp"

namespace vestige {
namespace rule {

Push::Push(std::string node, std::string into) : Rule(node)
{
    this->into = into;
}

int Push::valid(action::Action* action) {
    action::Push* a = dynamic_cast<action::Push*>( action );
    if (!a) { return 0; }
    
    if (a->node()->id() != node) { return 0; }
    if (a->into()->id() != into) { return 0; }
    
    return 1;
}

std::string Push::text() {
    return "Push(Node:" + node + "|Into:" + into + ")";
}

}}

