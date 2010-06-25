#include "Rule.hpp"

namespace vestige {
namespace rule {

Rule::Rule(std::string node)
{
    this->node = node;
    this->_clause = "";
}

std::string Rule::clause() { return this->_clause; }
void Rule::set_clause(std::string clause) { this->_clause = clause; }

int Rule::valid(action::Action* action) {
    return 0;
}

}}
