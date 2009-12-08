#include "Block.hpp"

namespace far{
namespace state{

Block::Block() : Node()
{
	id = "block";
}

void Block::print() {
	std::cout << id;
}

}}
