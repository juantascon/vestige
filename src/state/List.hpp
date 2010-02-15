#ifndef __VESTIGE_STATE_LIST_HPP
#define __VESTIGE_STATE_LIST_HPP

#include "Node.hpp"
#include "../lib/boost.hpp"

namespace vestige {
namespace state {

class List : public Node
{
	protected:
		
		
	public:
		List(marker::Marker *m);
		List(std::string id);
		
		state::Node::Vector* items;
		virtual void push(Node* n);
		int check_items_ids(std::vector<std::string>* ids);
		
		virtual std::string text();
		virtual Node::List* flat_view();
};

}}

#endif
