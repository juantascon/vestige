#include "Node.hpp"

namespace vestige {
namespace state {

Node::Node(marker::Marker* marker) {
    this->_marker = marker;
    this->_id = marker->id();
    this->_parent = NULL;
    this->_index = 0;
}

marker::Marker* Node::marker() { return this->_marker; }
std::string Node::id() { return this->_id; }
int Node::index() { return this->_index; }
Node* Node::parent() { return this->_parent; }

void Node::set_parent(Node* parent, int index) {
    _parent = parent;
    _index = index;
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
