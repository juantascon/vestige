#ifndef __FAR_STATE_LIST_HPP
#define __FAR_STATE_LIST_HPP

#include "Node.hpp"
#include "../lib/boost.hpp"

namespace far {
namespace state {

class List : public Node
{
	protected:
		
		
	public:
		List(marker::Marker *m);
		
		state::Node::Vector* items;
		
		virtual void push(Node* n);
		
		virtual void print();
		
		virtual Node::List* flat_view();
};

}}

#endif
