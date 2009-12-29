#include "Node.hpp"

namespace far{
namespace state{

Node::Node(marker::Marker *m)
{
	this->parent = 0;
	this->m = 0;
	this->id = "null";
	this->index = 0;
	
	if (m) {
		this->m = m;
		this->id = m->id;
	}
}

void Node::print() {
}

Node::List* Node::flat_view() {
	return new Node::List();
}

std::string Node::path() {
	if (parent) {
		return parent->path() + " / " + id;
	}
	else {
		return id;
	}
}

}}
