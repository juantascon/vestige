#include "Discard.hpp"

namespace vestige {
namespace action {

Discard::Discard(state::Node* item) : Action(item)
{
}

std::string Discard::text() {
    return "Action [Discard] | Item: " + item->path();
}

}}
