#include "EIncludes.hpp"

EState::EState() : ENodeList()
{
}

void EState::print() {
	std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
	
	for (int i = 0; i < _items.size(); i++) {
		_items[i]->print();
		std::cout << std::endl;
	}
	
	std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl << std::endl;
}
