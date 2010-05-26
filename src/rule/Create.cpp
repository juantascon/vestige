#include "Create.hpp"

namespace vestige {
namespace rule {

Create::Create(std::string node) : Rule(node)
{
}

int Create::valid(action::Action* action) {
    action::Create* a = dynamic_cast<action::Create*>( action );
    if (!a) { return 0; }
    
    if (a->node()->id() != node) { return 0; }
    
    return 1;
}

std::string Create::text() {
    return "Create(Node:" + node + ")";
}

}}
