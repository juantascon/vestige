#include "EIncludes.hpp"

EState::EState() : ENodeList()
{
}

void EState::print() {
	std::cout << "EState: " << std::endl;
	
	for (int i = 0; i < _items.size(); i++) {
		_items[i]->print();
	}
}
