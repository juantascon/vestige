#include "Node.hpp"
#include "NodeSet.hpp"
#include "../marker/Item.hpp"

namespace vestige {
namespace state {

Node::Node(marker::Marker* marker) {
    this->_marker = marker;
    this->_id = marker->id();
    this->_value = "";
    this->_children = new NodeSet();
    this->_parent = NULL;
    this->_index = 0;

    marker::Item* b = dynamic_cast<marker::Item*>(marker);
    if (b) { this->_value = b->value(); }
}

marker::Marker* Node::marker() { return this->_marker; }
std::string Node::id() { return this->_id; }
std::string Node::value() { return this->_value; }
int Node::index() { return this->_index; }
Node* Node::parent() { return this->_parent; }
NodeSet* Node::children() { return this->_children; }

void Node::add_child(Node* c) {
    c->set_parent(this);
    _children->push_back(c);
}

void Node::set_parent(Node* p) {
    _parent = p;
    _index = p->children()->size();
}

std::string Node::text() {
    return this->path();
}

void Node::alert(std::string message) {
    _marker->alert(message);
}

std::string Node::path() {
    if (_parent) {
        return _parent->path() + "/" + _id;
    }
    else {
        return _id;
    }
}

}}
