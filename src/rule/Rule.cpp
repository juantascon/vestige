#include "Rule.hpp"

namespace vestige {
namespace rule {

Rule::Rule(std::string node)
{
    this->node = node;
}

int Rule::valid(action::Action* action) {
    return 0;
}

}}
