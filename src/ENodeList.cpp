#include "EIncludes.hpp"

ENodeList::ENodeList() : ENode(), _items()
{
}

void ENodeList::push(ENode *n) {
	_items.push_back(n);
	n->parent = this;
}

ENode* ENodeList::pop() {
	//TODO: implementar
	return NULL;
}

void ENodeList::print() {
	std::cout << "-------------" << std::endl;
	for (int i = 0; i < _items.size(); i++) {
		std::cout << "-- ";
		_items[i]->print();
		std::cout << std::endl;
	}
	std::cout << "-------------";
}
