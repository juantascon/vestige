#include "Node.hpp"

namespace vestige {
namespace state {

Node::Node(marker::Marker* marker) {
    this->_marker = marker;
    this->_parent = NULL;
    this->_index_x = 0;
    this->_index_y = 0;
}

marker::Marker* Node::marker() { return this->_marker; }
std::string Node::id() { return this->_marker->id(); }

int Node::index_x() { return this->_index_x; }
int Node::index_y() { return this->_index_y; }
Node* Node::parent() { return this->_parent; }

void Node::set_index_x(int index_x) { this->_index_x = index_x; }
void Node::set_index_y(int index_y) { this->_index_y = index_y; }
void Node::set_parent(Node* parent) { _parent = parent; }

std::string Node::text() {
    return this->id();
}

void Node::alert(std::string message) {
    _marker->alert(message);
}

std::string Node::path() {
    if (_parent) {
        return _parent->path() + "/" + this->id();
    }
    else {
        return this->id();
    }
}

}}
