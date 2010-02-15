#ifndef __VESTIGE_ACTION_PUSH_HPP
#define __VESTIGE_ACTION_PUSH_HPP

#include "Action.hpp"

namespace vestige {
namespace action {

class Push : public Action
{
	protected:
		state::Node* into;
		
	public:
		Push(state::Node* item, state::Node* into);
		
		std::string into_id();
		
		std::string text();
};

}}

#endif
