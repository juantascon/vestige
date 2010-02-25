#include "Item.hpp"

namespace vestige {
namespace state {

Item::Item(marker::Item* marker) : Node(marker) {
    this->_value = marker->value();
}

std::string Item::value() { return this->_value; }

}}
