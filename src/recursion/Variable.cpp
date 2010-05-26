#include "Variable.hpp"

namespace vestige {
namespace recursion {

Variable::Variable(state::Node* node) {
    this->_node = node;
    this->in_main = "";
    this->in_head = "";
    this->out_main = "";
    this->out_head = "";
}

state::Node* Variable::node() { return this->_node; }

Variable* Variable::clone() {
    Variable* ret = new Variable(this->_node);
    ret->in_main = this->in_main;
    ret->in_head = this->in_head;
    ret->out_main = this->out_main;
    ret->out_head = this->out_head;
    
    return ret;
}

std::string Variable::text() {
    std::string ret = "node: " + _node->id();
    return ret;
}

}}
