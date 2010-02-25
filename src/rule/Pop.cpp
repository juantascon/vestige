#include "Pop.hpp"

namespace vestige {
namespace rule {

Pop::Pop(std::string node, std::string from) : Rule(node)
{
    this->from = from;
}

int Pop::valid(action::Action* action) {
    action::Pop* a = dynamic_cast<action::Pop*>( action );
    
    if (!a) { return 0; }
    
    if (a->node_id() != from) { return 0; }
    
    return 1;
}

std::string Pop::text() {
    return "Rule [Pop] | Node: " + node + " | From: " + from;
}

}}
