#include "List.hpp"
#include "NodeSet.hpp"

namespace vestige {
namespace state {

List::List(marker::List* marker) : Node(marker) {
    this->_children = new NodeSet();
}

NodeSet* List::children() { return this->_children; }

void List::add_child(Node* c) {
    c->set_parent(this, _children->size());
    _children->push_back(c);
}

}}
