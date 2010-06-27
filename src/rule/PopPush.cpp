#include "PopPush.hpp"

namespace vestige {
namespace rule {

PopPush::PopPush(std::string node, std::string from, std::string into, std::string clause) : Rule(node, clause)
{
    this->_from = from;
    this->_into = into;
}

int PopPush::valid(action::Action* action) {
    action::PopPush* a = dynamic_cast<action::PopPush*>( action );
    if (!a) { return 0; }
    
    if (a->node()->id() != _node) { return 0; }
    if (a->from()->id() != _from) { return 0; }
    if (a->into()->id() != _into) { return 0; }
    
    return 1;
}

std::string PopPush::text() {
    return "PopPush(Node:" + _node + "|From:" + _from + "|Into:" + _into + ")";
}

}}
