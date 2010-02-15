#ifndef __VESTIGE_STATE_BLOCK_HPP
#define __VESTIGE_STATE_BLOCK_HPP

#include "Node.hpp"

namespace vestige{
namespace state{

class Block : public Node
{
	private:
		
	public:
		Block(marker::Marker *m);
		Block(std::string id);
		
		virtual std::string text();
		virtual Node::List* flat_view();
};

}}

#endif
