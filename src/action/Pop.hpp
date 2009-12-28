#ifndef __FAR_ACTION_POP_HPP
#define __FAR_ACTION_POP_HPP

#include "Action.hpp"

namespace far {
namespace action {

class Pop : public Action
{
	protected:
		state::Node* from;
		
	public:
		Pop(state::Node* item, state::Node* from);
		
		std::string from_id();
		
		virtual void print();
};

}}

#endif
