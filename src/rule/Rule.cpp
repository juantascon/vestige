#include "Rule.hpp"

namespace vestige {
namespace rule {

Rule::Rule(Move* move, std::string clause)
{
    this->_move = move;
    this->_clause = clause;
}

std::string Rule::clause() { return this->_clause; }
Move* Rule::move() { return this->_move; }

std::string Rule::text() {
    return _move->text();
}

}}
