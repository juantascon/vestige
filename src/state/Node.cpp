#include "Node.hpp"

namespace vestige {
namespace state {

Node::Node(marker::Marker *m) {
	_initialize(m->id(), m, NULL, 0);
}

Node::Node(std::string id) {
	_initialize(id, NULL, NULL, 0);
}

void Node::_initialize(std::string id, marker::Marker* m, Node* parent, int index) {
	this->_id = id;
	this->_m = m;
	this->parent = parent;
	this->index = index;
}

std::string Node::id() { return this->_id; }

void Node::alert(std::string message) {
	_m->alert(message);
}

Node::List* Node::flat_view() {
	return new Node::List();
}

std::string Node::path() {
	if (parent) {
		return parent->path() + "/" + _id;
	}
	else {
		return _id;
	}
}

}}
