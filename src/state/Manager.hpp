#ifndef __FAR_STATE_MANAGER_HPP
#define __FAR_STATE_MANAGER_HPP

#include "Node.hpp"
#include "State.hpp"
#include "Block.hpp"
#include "../marker/Block.hpp"
#include "../marker/List.hpp"
#include "../marker/Manager.hpp"

namespace far{
namespace state{

class Manager
{
	protected:
		Manager();
		
		Node* do_block(marker::Block* b);
		Node* do_list(marker::List* l);
		
	public:
		static Manager* instance();
		
		State* current;
		State* capture();
		
};

}}

#endif
