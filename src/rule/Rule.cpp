#include "Rule.hpp"

namespace vestige {
namespace rule {

Rule::Rule(std::string node, std::string clause)
{
    this->_node = node;
    this->_clause = clause;
}

std::string Rule::clause() { return this->_clause; }

int Rule::valid(action::Action* action) {
    return 0;
}

}}
