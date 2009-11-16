#ifndef __FAR_STATE_NODE_HPP
#define __FAR_STATE_NODE_HPP

namespace far{
namespace state{

class Node
{
	public:
		Node();
		
		Node* parent;
		
		virtual void print();
};

typedef std::vector <Node*> NodeVector;

}}

#endif
