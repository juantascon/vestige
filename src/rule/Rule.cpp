#include "Rule.hpp"

namespace vestige {
namespace rule {

Rule::Rule(Move* move, std::string clause) {
    this->_move = move;
    this->_clause = clause;
}

Rule::Rule(Move* move, Names* names, std::string clause) {
    this->_move = move;
    this->_names = names;
    this->_clause = clause;
}

Move* Rule::move() { return this->_move; }
Names* Rule::names() { return this->_names; }
std::string Rule::clause() { return this->_clause; }

std::string Rule::text() {
    return _move->text();
}

}}
