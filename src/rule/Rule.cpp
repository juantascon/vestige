#include "Rule.hpp"

namespace far {
namespace rule {

Rule::Rule(std::string item)
{
	this->item = item;
}

int Rule::valid(action::Action* action) {
	return 0;
}

void Rule::print() {
	std::cout << "Rule [NULL] | Item: " << item << std::endl;
}

}}
