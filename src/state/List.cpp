#include "List.hpp"

namespace far{
namespace state{

List::List(marker::Marker *m) : Node(m), _items()
{
}

void List::push(Node *n) {
	n->index = _items.size();
	n->parent = this;
	
	_items.push_back(n);
}

Node* List::pop() {
	//TODO: implementar
	return NULL;
}

void List::print() {
	std::cout << "-------------------------------------------------------------" << std::endl;
	std::cout << "--- LIST-ID: " << this->id << std::endl;
	
	BOOST_FOREACH(Node *n, _items) {
		std::cout << "| ";
		n->print();
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------------";
}

Node::List* List::flat_view() {
	Node::List* l = new Node::List();
	
	l->push_back(this);
	
	BOOST_FOREACH(Node *n, _items) {
		l->splice(l->end(), *(n->flat_view()));
	}
	
	//D(("LIST SIZE=%i", l->size()));
	
	return l;
}

}}
