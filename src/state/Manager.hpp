#ifndef __FAR_STATE_MANAGER_HPP
#define __FAR_STATE_MANAGER_HPP

#include "../Includes.hpp"

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
