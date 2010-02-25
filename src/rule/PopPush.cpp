#include "PopPush.hpp"

namespace vestige {
namespace rule {

PopPush::PopPush(std::string node, std::string from, std::string into) : Rule(node)
{
    this->from = from;
    this->into = into;
}

int PopPush::valid(action::Action* action) {
    action::PopPush* a = dynamic_cast<action::PopPush*>( action );
    if (!a) { return 0; }
    
    if (a->node_id() != node) { return 0; }
    if (a->from_id() != from) { return 0; }
    if (a->into_id() != into) { return 0; }
    
    return 1;
}

std::string PopPush::text() {
    return "Rule [PopPush] | Node: " + node + " | From: " + from + " | Into: " + into;
}

}}
