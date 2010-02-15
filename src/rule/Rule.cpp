#include "Rule.hpp"

namespace vestige {
namespace rule {

Rule::Rule(std::string item)
{
	this->item = item;
}

int Rule::valid(action::Action* action) {
	return 0;
}

}}
