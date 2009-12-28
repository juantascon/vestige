#ifndef __FAR_ACTION_POPPUSH_HPP
#define __FAR_ACTION_POPPUSH_HPP

#include "Action.hpp"

namespace far {
namespace action {

class PopPush : public Action
{
	protected:
		state::Node* from;
		state::Node* into;
		
	public:
		PopPush(state::Node* item, state::Node* from, state::Node* into);
		
		std::string from_id();
		std::string into_id();
		
		virtual void print();
};

}}

#endif
