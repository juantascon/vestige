#ifndef __FAR_STATE_NODE_HPP
#define __FAR_STATE_NODE_HPP

#include "../Includes.hpp"

namespace far{
namespace state{

class Node
{
	public:
		typedef std::vector <Node*> Vector;
		
		Node();
		
		Node* parent;
		
		virtual void print();
		
		
};

}}

#endif
