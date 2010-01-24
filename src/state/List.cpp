#include "List.hpp"

namespace far {
namespace state {

List::List(marker::Marker *m) : Node(m)
{
	items = new state::Node::Vector();
}

List::List(std::string id) : Node(id)
{
	items = new state::Node::Vector();
}

void List::push(Node *n) {
	n->index = items->size();
	n->parent = this;
	
	items->push_back(n);
}

void List::print() {
	std::cout << "-------------------------------------------------------------" << std::endl;
	std::cout << "--- LIST-ID: " << this->id << std::endl;
	
	BOOST_FOREACH(Node *n, *items) {
		std::cout << "| ";
		n->print();
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------------";
}

Node::List* List::flat_view() {
	Node::List* l = new Node::List();
	
	l->push_back(this);
	
	BOOST_FOREACH(Node *n, *items) {
	
		l->splice(l->end(), *(n->flat_view()));
	}
	
	//D(("LIST SIZE=%i", l->size()));
	return l;
}

}}
