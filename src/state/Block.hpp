#ifndef __FAR_STATE_BLOCK_HPP
#define __FAR_STATE_BLOCK_HPP

#include "Node.hpp"

namespace far{
namespace state{

class Block : public Node
{
	private:
		
	public:
		Block ();
		std::string id;
		
		virtual void print();
};

}}

#endif
