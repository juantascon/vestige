#include "List.hpp"

namespace far{
namespace state{

List::List() : Node(), _items()
{
}

void List::push(Node *n) {
	_items.push_back(n);
	n->parent = this;
}

Node* List::pop() {
	//TODO: implementar
	return NULL;
}

void List::print() {
	std::cout << "-------------" << std::endl;
	for (int i = 0; i < _items.size(); i++) {
		std::cout << "-- ";
		_items[i]->print();
		std::cout << std::endl;
	}
	std::cout << "-------------";
}

}}
