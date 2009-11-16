#ifndef __ENODE_H
#define __ENODE_H 1

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
