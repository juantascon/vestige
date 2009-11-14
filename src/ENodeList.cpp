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
	std::cout << "-------------";
	for (int i = 0; i < _items.size(); i++) {
		std::cout << std::endl << "|";
		_items[i]->print();
		std::cout << "|";
	}
}
