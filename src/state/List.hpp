#ifndef __FAR_STATE_LIST_HPP
#define __FAR_STATE_LIST_HPP

#include "Node.hpp"
#include "../lib/boost.hpp"

namespace far {
namespace state {

class List : public Node
{
	protected:
		state::Node::Vector _items;
		
	public:
		List(marker::Marker *m);
		
		virtual void push(Node* n);
		Node* pop();
		
		virtual void print();
		
		virtual Node::List* flat_view();
};

}}

#endif
