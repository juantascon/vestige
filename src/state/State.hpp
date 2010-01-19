#ifndef __FAR_STATE_STATE_HPP
#define __FAR_STATE_STATE_HPP

#include "List.hpp"
#include "../action/Types.hpp"

namespace far {
namespace state {

class State : public List
{
	protected:
		
	public:
		State();
		
		Node::List* flat_items;
		Node* output;
		
		virtual void push(Node *n);
		virtual void print();
		
		void create_flat_view();
		
		action::Action::Vector* diff(State* comp);
};

}}

#endif
