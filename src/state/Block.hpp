#ifndef __FAR_STATE_BLOCK_HPP
#define __FAR_STATE_BLOCK_HPP

#include "Node.hpp"

namespace far{
namespace state{

class Block : public Node
{
	private:
		
	public:
		Block(marker::Marker *m);
		Block(std::string id);
		
		virtual void print();
		virtual Node::List* flat_view();
};

}}

#endif
