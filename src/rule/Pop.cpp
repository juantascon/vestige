#include "Pop.hpp"

namespace vestige {
namespace rule {

Pop::Pop(std::string node, std::string from, std::string clause) : Rule(node, clause)
{
    this->_from = from;
}

int Pop::valid(action::Action* action) {
    action::Pop* a = dynamic_cast<action::Pop*>( action );
    
    if (!a) { return 0; }
    
    if (a->node()->id() != _node) { return 0; }
    if (a->from()->id() != _from) { return 0; }
    
    return 1;
}

std::string Pop::text() {
    return "Pop(Node:" + _node + "|From:" + _from + ")";
}

}}
