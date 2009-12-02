#ifndef __FAR_STATE_LIST_HPP
#define __FAR_STATE_LIST_HPP

#include "Node.hpp"

namespace far{
namespace state{

class List : public Node
{
	private:
		
	protected:
		NodeVector _items;
		
	public:
		List();
		
		void push(Node* n);
		Node* pop();
		virtual void print();
};

}}

#endif
