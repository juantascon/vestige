#include "Push.hpp"

namespace vestige {
namespace rule {

Push::Push(std::string item, std::string into) : Rule(item)
{
    this->into = into;
}

int Push::valid(action::Action* action) {
    action::Push* a = dynamic_cast<action::Push*>( action );
    if (!a) { return 0; }
    
    if (a->item_id() != item) { return 0; }
    if (a->into_id() != into) { return 0; }
    
    return 1;
}

std::string Push::text() {
    return "Rule [Push] || Item: " + item + " || Into: " + into;
}

}}

