#ifndef __ENODELIST_H
#define __ENODELIST_H

#include "../Includes.hpp"

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
