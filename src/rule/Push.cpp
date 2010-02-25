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
    
    if (a->node_id() != node) { return 0; }
    if (a->into_id() != into) { return 0; }
    
    return 1;
}

std::string Push::text() {
    return "Rule [Push] || Node: " + node + " || Into: " + into;
}

}}

