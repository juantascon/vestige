#include "State.hpp"
#include "List.hpp"

namespace far{
namespace state{

State::State() : List()
{
}

void State::print() {
	std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
	
	for (int i = 0; i < _items.size(); i++) {
		_items[i]->print();
		std::cout << std::endl;
	}
	
	std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl << std::endl;
}

}}
