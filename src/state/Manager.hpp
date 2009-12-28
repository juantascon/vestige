#ifndef __FAR_STATE_MANAGER_HPP
#define __FAR_STATE_MANAGER_HPP

#include "Node.hpp"
#include "State.hpp"
#include "Block.hpp"
#include "Supervisor.hpp"

#include "../marker/Block.hpp"
#include "../marker/List.hpp"
#include "../marker/Manager.hpp"

#include "../rule/RuleSet.hpp"

namespace far{
namespace state{

class Manager
{
	protected:
		Manager();
		
		marker::Marker::List* markers;
		void sort_markers();
		
		Node* do_block(marker::Marker* m);
		Node* do_list(marker::Marker* m);
		
	public:
		static Manager* instance();
		
		State* current;
		State* capture();
		void step();
};

}}

#endif
