#include "Node.hpp"

namespace far {
namespace state {

Node::Node(marker::Marker *m) {
	_initialize(m->id, m, NULL, 0);
}

Node::Node(std::string id) {
	_initialize(id, NULL, NULL, 0);
}

void Node::_initialize(std::string id, marker::Marker* m, Node* parent, int index) {
	this->id = id;
	this->m = m;
	this->parent = parent;
	this->index = index;
}

Node::List* Node::flat_view() {
	return new Node::List();
}
std::string Node::path() {
	if (parent) {
		return parent->path() + "/" + id;
	}
	else {
		return id;
	}
}

}}
