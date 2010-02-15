#include "Block.hpp"

namespace vestige{
namespace state{

Block::Block(marker::Marker *m) : Node(m)
{
}

Block::Block(std::string id) : Node(id)
{
}

std::string Block::text() {
	return "BLOCK-ID: " + id;
}

Node::List* Block::flat_view() {
	Node::List* l = new Node::List();
	
	l->push_back(this);
	
	//D(("BLOCK SIZE=%i", l->size()));
	
	return l;
}

}}
